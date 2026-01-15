//
// Created by duhamel on 15/01/2026.
//

#ifndef SIMULATION_PROJECT_BRENCHMARK_H
#define SIMULATION_PROJECT_BRENCHMARK_H
#include <string>
using BenchFn = void(*)();
class BenchMarkManager;
class BenchMarkTest;
class BenchMarkRegister
{
    public:
    static BenchMarkTest& add_benchmark_test(BenchMarkTest &bench_mark,std::string category="default");
};
class BenchMarkTest
{
    public:
    /**
     * @brief give the test's name
     * @return the name of test
     */
    const std::string& get_name() const
    {
        return name;
    }

    /**
 * @brief Get the line number where the benchmark was declared.
 *        Récupère le numéro de ligne où le benchmark a été déclaré.
 * @return The line number.
 *         Numéro de ligne.
 */
    int get_line() const
    {
        return line;
    }
    /**
 * @brief Get the file where the benchmark was declared.
 *        Récupère le fichier où le benchmark a été déclaré.
 * @return The file.
 *         Nom du fichier.
 */
    const std::string& get_file() const
    {
        return file;
    }
    virtual void run();//TODO signature à changer
    virtual ~BenchMarkTest()=default;


protected:
    BenchMarkTest(std::string name,int line,std::string file);
    private:
    const std::string name;
    const int line;
    const std::string file;
};



#endif //SIMULATION_PROJECT_BRENCHMARK_H