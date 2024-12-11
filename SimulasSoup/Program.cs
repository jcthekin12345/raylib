using System;
using System.Net.Http;
using System.Threading.Tasks;
using System.Text.Json;

namespace SimulasSoup
{


    internal class Program
    {
        enum FoodType
        {
            SOUP,
            STEW,
            GUMBO
        }

        enum MainIngredients
        {
            MUSHROOMS,
            CHICKEN,
            CARROTS,
            POTATOES,
        }

        enum Seasoning
        {
            SPICY,
            SALTY,
            SWEET,
        };
        static void CreateDish()
        {
            while (true)
            {
                Console.WriteLine("What type of food will you be making? ");
                Console.WriteLine();
                Console.WriteLine("=======");
                Console.WriteLine("[A]Soup");
                Console.WriteLine("[B]Stew");
                Console.WriteLine("[C]Gumbo");
                string? userInput = Console.ReadLine().ToLower();
                if (userInput != null)
                {
                    Console.WriteLine("ayyy enter something...");
                }
               
               
   
            }
       }
        static void Main(string[] args)
        {
            (FoodType, MainIngredients, Seasoning) dish = (FoodType.SOUP, MainIngredients.MUSHROOMS, Seasoning.SPICY);
            Console.WriteLine("Hello, World!");
        }
    }
}
