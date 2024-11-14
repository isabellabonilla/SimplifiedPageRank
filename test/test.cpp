////Author: Isabella Bonilla
//#include <catch2/catch_test_macros.hpp>
//#include <iostream>
//#include <sstream>
//#include "AdjacencyList.h"
//using namespace std;
//
//// 5 unique, meaningful tests
//
//TEST_CASE("Test 1: Single Link", "[flag]") { // only one link from facebook to instagram
//    string input = R"(1 2
//facebook.com instagram.com)";
//
//    string expectedOutput = R"(facebook.com 0.00
//instagram.com 0.50
//)";
//
//    string actualOutput;
//    istringstream ss(input); // reading from input string
//
//    int no_of_lines, power_iterations;
//    ss >> no_of_lines >> power_iterations; // parse and read number of lines and number of power iterations
//
//    AdjacencyList graph; // create graph object
//    map<string, AdjacencyList::Webpage*> webpages; // keeps track of all webpages
//
//    for (int i = 0; i < no_of_lines; i++) {
//        string from, to;
//        ss >> from >> to; // parse and read from webpage and to webpage
//
//        if(webpages.find(from) == webpages.end()) { // if new webpage, add to map and create Webpage object
//            AdjacencyList::Webpage* fromPage = new AdjacencyList::Webpage(from);
//            webpages[from] = fromPage;
//        }
//        if(webpages.find(to) == webpages.end()) { // if new webpage, add to map and create Webpage object
//            AdjacencyList::Webpage* toPage = new AdjacencyList::Webpage(to);
//            webpages[to] = toPage;
//        }
//
//        graph.insertEdge(webpages[from], webpages[to]); // insert edge
//    }
//
//    actualOutput = graph.PageRank(power_iterations); // store output of pageRank function
//
//    for(auto& page : webpages) { // delete all Webpage objects
//        delete page.second;
//    }
//
//    REQUIRE(actualOutput == expectedOutput); // check if produced output matches expected output
//}
//
//TEST_CASE("Test 2: Circular Link", "[flag]") { // circular link between google, samsung, and microsoft
//    string input = R"(6 4
//google.com samsung.com
//samsung.com microsoft.com
//microsoft.com google.com
//github.com google.com
//maps.com ufl.edu
//samsung.com maps.com)";
//
//    string expectedOutput = R"(github.com 0.00
//google.com 0.08
//maps.com 0.17
//microsoft.com 0.17
//samsung.com 0.08
//ufl.edu 0.08
//)";
//
//    string actualOutput;
//    istringstream ss(input); // reading from input string
//
//    int no_of_lines, power_iterations;
//    ss >> no_of_lines >> power_iterations; // parse and read number of lines and number of power iterations
//
//    AdjacencyList graph; // create graph object
//    map<string, AdjacencyList::Webpage*> webpages; // keeps track of all webpages
//
//    for (int i = 0; i < no_of_lines; i++) {
//        string from, to;
//        ss >> from >> to; // parse and read from webpage and to webpage
//
//        if(webpages.find(from) == webpages.end()) { // if new webpage, add to map and create Webpage object
//            AdjacencyList::Webpage* fromPage = new AdjacencyList::Webpage(from);
//            webpages[from] = fromPage;
//        }
//        if(webpages.find(to) == webpages.end()) { // if new webpage, add to map and create Webpage object
//            AdjacencyList::Webpage* toPage = new AdjacencyList::Webpage(to);
//            webpages[to] = toPage;
//        }
//
//        graph.insertEdge(webpages[from], webpages[to]); // insert edge
//    }
//
//    actualOutput = graph.PageRank(power_iterations); // store output of pageRank function
//
//    for(auto& page : webpages) { // delete all Webpage objects
//        delete page.second;
//    }
//
//    REQUIRE(actualOutput == expectedOutput); // check if produced output matches expected output
//}
//
//TEST_CASE("Test 3: Large Input", "[flag]") { // large input of 161
//    string input = R"(161 1
//ufl.edu samsung.com
//microsoft.com wikipedia.org
//mozilla.org stackoverflow.com
//facebook.com chase.com
//disney.com weather.com
//weather.com microsoft.com
//ufl.edu pcbuildinguf.com
//getbootstrap.com facebook.com
//chase.com mozilla.org
//wikipedia.org zoom.us
//openai.com twitter.com
//wikipedia.org facebook.com
//stackoverflow.com getbootstrap.com
//youtube.com instagram.com
//google.com roblox.com
//weather.com pcbuildinguf.com
//youtube.com mozilla.org
//aman.com stackoverflow.com
//getbootstrap.com instagram.com
//twitter.com youtube.com
//pcbuildinguf.com stackoverflow.com
//wikipedia.org weather.com
//weather.com openai.com
//pcbuildinguf.com mozilla.org
//weather.com python.org
//disney.com samsung.com
//youtube.com zoom.us
//ufl.edu wikipedia.org
//twitter.com openai.com
//youtube.com github.com
//zoom.us pcbuildinguf.com
//openai.com getbootstrap.com
//instagram.com reactjs.org
//facebook.com mozilla.org
//pcbuildinguf.com github.com
//pcbuildinguf.com instagram.com
//facebook.com weather.com
//weather.com reactjs.org
//openai.com pcbuildinguf.com
//pcbuildinguf.com google.com
//disney.com getbootstrap.com
//mozilla.org zoom.us
//facebook.com samsung.com
//chase.com python.org
//chase.com disney.com
//disney.com youtube.com
//google.com instagram.com
//reactjs.org disney.com
//weather.com wikipedia.org
//github.com getbootstrap.com
//facebook.com stackoverflow.com
//facebook.com twitter.com
//zoom.us google.com
//instagram.com mozilla.org
//google.com wikipedia.org
//mozilla.org openai.com
//facebook.com ufl.edu
//chase.com reactjs.org
//facebook.com wikipedia.org
//openai.com instagram.com
//zoom.us reactjs.org
//samsung.com python.org
//samsung.com wikipedia.org
//aman.com google.com
//zoom.us openai.com
//stackoverflow.com aman.com
//stackoverflow.com openai.com
//disney.com ufl.edu
//openai.com zoom.us
//aman.com python.org
//stackoverflow.com zoom.us
//python.org disney.com
//stackoverflow.com pcbuildinguf.com
//github.com disney.com
//disney.com aman.com
//reactjs.org microsoft.com
//wikipedia.org aman.com
//getbootstrap.com reactjs.org
//microsoft.com zoom.us
//samsung.com github.com
//samsung.com youtube.com
//stackoverflow.com microsoft.com
//twitter.com pcbuildinguf.com
//stackoverflow.com instagram.com
//google.com disney.com
//disney.com mozilla.org
//instagram.com getbootstrap.com
//zoom.us github.com
//getbootstrap.com aman.com
//zoom.us roblox.com
//roblox.com twitter.com
//instagram.com disney.com
//microsoft.com chase.com
//ufl.edu weather.com
//reactjs.org twitter.com
//microsoft.com google.com
//python.org google.com
//stackoverflow.com google.com
//disney.com reactjs.org
//youtube.com disney.com
//getbootstrap.com microsoft.com
//google.com facebook.com
//github.com chase.com
//disney.com zoom.us
//stackoverflow.com ufl.edu
//mozilla.org weather.com
//getbootstrap.com openai.com
//roblox.com google.com
//openai.com mozilla.org
//samsung.com aman.com
//samsung.com getbootstrap.com
//microsoft.com aman.com
//instagram.com github.com
//twitter.com wikipedia.org
//getbootstrap.com samsung.com
//wikipedia.org python.org
//openai.com google.com
//aman.com facebook.com
//samsung.com weather.com
//python.org roblox.com
//facebook.com reactjs.org
//microsoft.com reactjs.org
//github.com weather.com
//python.org youtube.com
//python.org reactjs.org
//twitter.com microsoft.com
//reactjs.org mozilla.org
//openai.com weather.com
//aman.com chase.com
//youtube.com chase.com
//facebook.com google.com
//ufl.edu chase.com
//zoom.us twitter.com
//wikipedia.org google.com
//chase.com wikipedia.org
//facebook.com youtube.com
//mozilla.org getbootstrap.com
//zoom.us samsung.com
//wikipedia.org youtube.com
//roblox.com mozilla.org
//python.org twitter.com
//youtube.com samsung.com
//chase.com ufl.edu
//google.com mozilla.org
//openai.com chase.com
//twitter.com mozilla.org
//disney.com microsoft.com
//github.com reactjs.org
//mozilla.org twitter.com
//chase.com youtube.com
//reactjs.org google.com
//roblox.com reactjs.org
//mozilla.org facebook.com
//roblox.com disney.com
//instagram.com openai.com
//twitter.com google.com
//mozilla.org github.com
//ufl.edu openai.com
//samsung.com mozilla.org
//facebook.com zoom.us
//youtube.com reactjs.org)";
//
//    string expectedOutput = R"(aman.com 0.04
//chase.com 0.04
//disney.com 0.04
//facebook.com 0.04
//getbootstrap.com 0.04
//github.com 0.04
//google.com 0.04
//instagram.com 0.04
//microsoft.com 0.04
//mozilla.org 0.04
//openai.com 0.04
//pcbuildinguf.com 0.04
//python.org 0.04
//reactjs.org 0.04
//roblox.com 0.04
//samsung.com 0.04
//stackoverflow.com 0.04
//twitter.com 0.04
//ufl.edu 0.04
//weather.com 0.04
//wikipedia.org 0.04
//youtube.com 0.04
//zoom.us 0.04
//)";
//
//    string actualOutput;
//    istringstream ss(input); // reading from input string
//
//    int no_of_lines, power_iterations;
//    ss >> no_of_lines >> power_iterations; // parse and read number of lines and number of power iterations
//
//    AdjacencyList graph; // create graph object
//    map<string, AdjacencyList::Webpage*> webpages; // keeps track of all webpages
//
//    for (int i = 0; i < no_of_lines; i++) {
//        string from, to;
//        ss >> from >> to; // parse and read from webpage and to webpage
//
//        if(webpages.find(from) == webpages.end()) { // if new webpage, add to map and create Webpage object
//            AdjacencyList::Webpage* fromPage = new AdjacencyList::Webpage(from);
//            webpages[from] = fromPage;
//        }
//        if(webpages.find(to) == webpages.end()) { // if new webpage, add to map and create Webpage object
//            AdjacencyList::Webpage* toPage = new AdjacencyList::Webpage(to);
//            webpages[to] = toPage;
//        }
//
//        graph.insertEdge(webpages[from], webpages[to]); // insert edge
//    }
//
//    actualOutput = graph.PageRank(power_iterations); // store output of pageRank function
//
//    for(auto& page : webpages) { // delete all Webpage objects
//        delete page.second;
//    }
//
//    REQUIRE(actualOutput == expectedOutput); // check if produced output matches expected output
//}
//
//TEST_CASE("Test 4: Low Power Iterations", "[flag]") { // power iteration of only 3
//    string input = R"(10 3
//python.org google.com
//reactjs.org microsoft.com
//roblox.com pcbuildinguf.com
//stackoverflow.com python.org
//stackoverflow.com aman.com
//mozilla.org stackoverflow.com
//google.com reactjs.org
//weather.com github.com
//zoom.us ufl.edu
//ufl.edu aman.com)";
//
//    string expectedOutput = R"(aman.com 0.12
//github.com 0.00
//google.com 0.04
//microsoft.com 0.08
//mozilla.org 0.00
//pcbuildinguf.com 0.00
//python.org 0.04
//reactjs.org 0.08
//roblox.com 0.00
//stackoverflow.com 0.00
//ufl.edu 0.00
//weather.com 0.00
//zoom.us 0.00
//)";
//
//    string actualOutput;
//    istringstream ss(input); // reading from input string
//
//    int no_of_lines, power_iterations;
//    ss >> no_of_lines >> power_iterations; // parse and read number of lines and number of power iterations
//
//    AdjacencyList graph; // create graph object
//    map<string, AdjacencyList::Webpage*> webpages; // keeps track of all webpages
//
//    for (int i = 0; i < no_of_lines; i++) {
//        string from, to;
//        ss >> from >> to; // parse and read from webpage and to webpage
//
//        if(webpages.find(from) == webpages.end()) { // if new webpage, add to map and create Webpage object
//            AdjacencyList::Webpage* fromPage = new AdjacencyList::Webpage(from);
//            webpages[from] = fromPage;
//        }
//        if(webpages.find(to) == webpages.end()) { // if new webpage, add to map and create Webpage object
//            AdjacencyList::Webpage* toPage = new AdjacencyList::Webpage(to);
//            webpages[to] = toPage;
//        }
//
//        graph.insertEdge(webpages[from], webpages[to]); // insert edge
//    }
//
//    actualOutput = graph.PageRank(power_iterations); // store output of pageRank function
//
//    for(auto& page : webpages) { // delete all Webpage objects
//        delete page.second;
//    }
//
//    REQUIRE(actualOutput == expectedOutput); // check if produced output matches expected output
//}
//
//TEST_CASE("Test 5: High Power Iterations", "[flag]") { // power iteration of 17
//    string input = R"(16 253
//pcbuildinguf.com youtube.com
//pcbuildinguf.com github.com
//chase.com google.com
//weather.com mozilla.org
//python.org youtube.com
//twitter.com google.com
//instagram.com twitter.com
//github.com google.com
//microsoft.com pcbuildinguf.com
//ufl.edu instagram.com
//aman.com getbootstrap.com
//getbootstrap.com instagram.com
//mozilla.org ufl.edu
//reactjs.org weather.com
//weather.com wikipedia.org
//apple.com stackoverflow.com)";
//
//    string expectedOutput = R"(aman.com 0.00
//apple.com 0.00
//chase.com 0.00
//getbootstrap.com 0.00
//github.com 0.00
//google.com 0.00
//instagram.com 0.00
//microsoft.com 0.00
//mozilla.org 0.00
//pcbuildinguf.com 0.00
//python.org 0.00
//reactjs.org 0.00
//stackoverflow.com 0.00
//twitter.com 0.00
//ufl.edu 0.00
//weather.com 0.00
//wikipedia.org 0.00
//youtube.com 0.00
//)";
//
//    string actualOutput;
//    istringstream ss(input); // reading from input string
//
//    int no_of_lines, power_iterations;
//    ss >> no_of_lines >> power_iterations; // parse and read number of lines and number of power iterations
//
//    AdjacencyList graph; // create graph object
//    map<string, AdjacencyList::Webpage*> webpages; // keeps track of all webpages
//
//    for (int i = 0; i < no_of_lines; i++) {
//        string from, to;
//        ss >> from >> to; // parse and read from webpage and to webpage
//
//        if(webpages.find(from) == webpages.end()) { // if new webpage, add to map and create Webpage object
//            AdjacencyList::Webpage* fromPage = new AdjacencyList::Webpage(from);
//            webpages[from] = fromPage;
//        }
//        if(webpages.find(to) == webpages.end()) { // if new webpage, add to map and create Webpage object
//            AdjacencyList::Webpage* toPage = new AdjacencyList::Webpage(to);
//            webpages[to] = toPage;
//        }
//
//        graph.insertEdge(webpages[from], webpages[to]); // insert edge
//    }
//
//    actualOutput = graph.PageRank(power_iterations); // store output of pageRank function
//
//    for(auto& page : webpages) { // delete all Webpage objects
//        delete page.second;
//    }
//
//    REQUIRE(actualOutput == expectedOutput); // check if produced output matches expected output
//}
