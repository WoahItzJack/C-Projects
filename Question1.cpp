#include <iostream>                                         // Include the string library
#include <string>                                           //learn about include statements, cause they are clarly breaking your code
#include <fstream> 
int main(){

    const double Coffee = 15.00;
    const double Sandwich = 30.00;
    const double Salad = 25.00;
    const double Juice = 10.00;
    const double Muffin = 20.00;
    const double Pizza = 35.00;
    const double Soup = 18.00;
    const double Burger = 40.00;


    std::string name;
    std::string surname;
    int x = 0;
    std::cout << "Enter your name: ";        
    std::cin >> name;
    std::cout << "Enter your surname: ";
    std::cin >> surname;

    std::cout << "How many items would you like to order (up to 8)? ";
    std::cin >> x;
    std::cout << "\n\nCafateria Menu:\n";
    
    std::cout << "1. Coffee - R15.00\n";
    std::cout << "2. Sandwich - R30.00\n";
    std::cout << "3. Salad - R25.00\n";
    std::cout << "4. Juice - R10.00\n";
    std::cout << "5. Muffin - R20.00\n";
    std::cout << "6. Pizza Slice - R35.00\n";
    std::cout << "7. Soup - R18.00\n";
    std::cout << "8. Burger - R40.00\n";

    double totalcost = 0;  
    double finalcost = 0;
    int y;
    
    for (int i = 0; i < x;++i){                                                                        //  for loop knowledge 4 later    (i=i+1 or ++i)  
        std::cout << "Select item " << i+1 << " (1-8): ";      //  dont ++, the i inside the loop will display the current loop +1 bc array =0+whatever
        std::cin >> y;
        if (y)if (y == 1) {
            totalcost = totalcost + 15.00;
        }
        else if (y == 2) {
            totalcost = totalcost + 30.00;
        }
        else if (y == 3) {
            totalcost = totalcost + 25.00;
        }
        else if (y == 4) {
            totalcost = totalcost + 10.00;
        }
        else if (y == 5) {
            totalcost = totalcost + 20.00;
        }
        else if (y == 6) {
            totalcost = totalcost +35.00;
        }
        else if (y == 7) {
            totalcost = totalcost +18.00;
        }
        else if (y == 8) {
            totalcost = totalcost + 40.00;
        }

    }
    std::cout << "Total Bill: " << totalcost <<"\n";

    if (totalcost >= 100){
        finalcost = totalcost - (totalcost/10);
        std::cout << "10% Discount applied\n";
        
    }

    else {
        std::cout << "No discount applied\n";
        finalcost = totalcost + finalcost;
    }
   
    std::cout << "Final Bill: " << finalcost;

    //File stuff
    std::ofstream outputFile("Cafateria.txt"); 

    if (outputFile.is_open()) { 
    outputFile << name << surname << finalcost;                    //this is your data input
    outputFile.close(); 
    std::cout << "\nThe bill has been written to Cafateria.txt\n";
    }
        else {
            std::cerr << "Error opening file\n";
    }

        return 0;
    
}
