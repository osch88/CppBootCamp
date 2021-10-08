#include <iostream>
#include <fstream>

void Something(){
    // Create a text string, which is used to output the text file
    std::string csvString;

    // Read from the text file
    std::ifstream InputFile("unsolved.csv");

    if( InputFile.is_open() ) std::cout << "YES\n\n";
    // Use a while loop together with the getline() function to read the file line by line
    while (std::getline (InputFile, csvString)) {
        // Output the text from the file
        int i = 0;
        for (char c:csvString){
            if(c != ','){
                std::cout << c << " ";
                i++;
            }
            if(i == 9){
                std::cout << "\n";
                i = 0;
            }
        }
        
    }

    std::cout << "\n";


    // Close the file
    InputFile.close();
}

int main(){
    Something();
}