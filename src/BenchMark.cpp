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


    
};