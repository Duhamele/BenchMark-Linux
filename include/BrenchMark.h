//
// Created by duhamel on 15/01/2026.
//

#ifndef SIMULATION_PROJECT_BRENCHMARK_H
#define SIMULATION_PROJECT_BRENCHMARK_H
#include <string>
using BenchFn = void(*)();

class BenchMarkTest;
class BenchMarkRegister
{
    public:
    static BenchMarkTest* add_benchmark_test(BenchMarkTest* bench_mark,std::string category="default");
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
    virtual void run()=0;//TODO signature à changer
    virtual ~BenchMarkTest()=default;


protected:
    /**
     * @brief Constructor of the virtual class BenchMarkTest for data.
     *        Constructeur de la classe virtuelle BenchMarkTest pour les données.
     *
     * @param name The name of the benchmark.
     *             Le nom du benchmark.
     * @param line The line number where the benchmark was declared (using the __LINE__ macro).
     *             Le numéro de ligne où le benchmark a été déclaré (en utilisant la macro __LINE__).
     * @param file The file where the benchmark was declared (using the __FILE__ macro).
     *             Le fichier où le benchmark a été déclaré (en utilisant la macro __FILE__).
     */
    BenchMarkTest(std::string name,int line,std::string file);
    private:
    const std::string name;
    const int line;
    const std::string file;
};



#endif //SIMULATION_PROJECT_BRENCHMARK_H