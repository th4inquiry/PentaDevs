using System.Collections.Generic;
using System.Linq;

namespace CSharpV3.QueryExpression
{
    public class RunExample3
    {
        class Country
        {
            public IEnumerable<City> Cities;
        }

        class City
        {
            public City()
            {

            }

            public City(string defaultName, int defaultPopulation)
            {
                name = defaultName;
                population = defaultPopulation;
            }

            public string name;
            public int population;
        }

        public RunExample3()
        {
            TestExecute();
        }

        private void TestExecute()
        {
            var scores = new[] { 90, 71, 82, 93, 75, 82, 50, 60, 70, 80, 90, 100 };

            IEnumerable<int> highScoresQuery =
                from score in scores
                where score > 80
                orderby score descending
                select score;

            foreach (int highscore in highScoresQuery)
            {
                System.Console.WriteLine(highscore);
            }

            Country Korea = new Country();
            Country USA = new Country();

            IEnumerable<Country> countries = new List<Country> { Korea, USA };

            City Seoul = new City("Seoul", 100000);
            City Busan = new City("Busan", 1000);
            City Seattle = new City("Seattle", 50000);
            City Issaquah = new City("Issaquah", 20000);

            Korea.Cities = new List<City> { Seoul, Busan };
            USA.Cities = new List<City> { Seattle, Issaquah };

            IEnumerable<City> largeCitiesList =
                from country in countries
                from city in country.Cities
                where city.population > 10000
                select city;

            List<City> largeCitiesList2 = largeCitiesList.ToList();

            foreach (City largeCity in largeCitiesList2)
            {
                System.Console.WriteLine(largeCity.name);
            }
        }
    }
}