#include <deque>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "BrenchMark.h"
//
// Created by duhamel on 16/01/2026.
//
class BenchMarkManager
{
public:
    static constexpr std::string_view master_category = "@all";



    std::map<std::string,std::vector<std::string>> benchmarks_category;
    std::map<std::string,std::vector<BenchMarkTest>> benchmarks;

    BenchMarkManager()
    {
        benchmarks_category.emplace(
            std::string(master_category),
            std::vector<std::string>{"default"});
    }
    bool check()
    {
        std::set<std::string> all_categories={};
        std::deque<std::string> queue={std::string(master_category)};
        while(!queue.empty())
        {
            std::string item=queue.front();
            queue.pop_front();
            if (all_categories.contains(item))
            {
                return false;
            }
            all_categories.insert(item);
            queue.insert(queue.end(), benchmarks_category[item].begin(), benchmarks_category[item].end());
        }
        for (auto item :benchmarks)
        {
            if (!all_categories.contains(item.first))
            {
                return false;
            }
        }
        return true;


    }
    BenchMarkTest& add_benchmark(BenchMarkTest bench_mark, std::string category)
    {
        if (benchmarks.contains(category))
        {
            benchmarks[category].push_back(bench_mark);
            return benchmarks[category].back();
        }
        else
        {
            benchmarks.insert({category,{bench_mark}});//TODO à verify
            return benchmarks[category].back();
        }
    }


    
};

BenchMarkManager* bench_mark_manager;
BenchMarkTest& BenchMarkRegister::add_benchmark_test(BenchMarkTest bench_mark, std::string category)
{
    static BenchMarkManager manager;
    bench_mark_manager=&manager;
    return manager.add_benchmark(bench_mark,category);
}
