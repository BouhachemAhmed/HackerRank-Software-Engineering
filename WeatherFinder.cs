using System;                  // Provides basic functionalities
using System.Net;              // Allows working with HTTP requests
using Newtonsoft.Json.Linq;    // Allows working with JSON data (requires Newtonsoft.Json package)

class Result
{
    /*
     * Function to get the temperature of a city
     * Uses WebClient to send an HTTP GET request
     */
    public static int getTemperature(string name)
    {
        // URL for the API with the specified city name
        string url = $"https://jsonmock.hackerrank.com/api/weather?name={name}";
        
        using (WebClient client = new WebClient())
        {
            try
            {
                // Fetches the JSON response from the URL
                string jsonResponse = client.DownloadString(url);
                
                // Parses the JSON response
                JObject jsonObject = JObject.Parse(jsonResponse);
                
                // Extracts the temperature value from JSON data
                string weatherString = jsonObject["data"][0]["weather"].ToString();
                
                // Extracts and parses the integer temperature from the "weather" string
                int temperature = int.Parse(weatherString.Split(' ')[0]);
                
                return temperature; // Returns the temperature
            }
            catch (Exception ex)
            {
                Console.WriteLine("An error occurred: " + ex.Message);
                return -1; // Returns -1 in case of an error
            }
        }
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        // Reads the city name from input
        string name = Console.ReadLine();

        // Calls the getTemperature function and stores the result
        int result = Result.getTemperature(name);

        // Outputs the temperature result
        Console.WriteLine(result);
    }
}
