#include <iostream>
#include "Book.h"
#include "BookRepo.h"
#include <string>
#include "Controller.h"
#include "UI.h"

int main()
{
    //password for Administrator Mode is 'admin'
    Controller ctrl;
    BookRepo repo;
    loadAudioBookData(&ctrl);
    displayUI(&ctrl);
 



































    //Book x("ye","ye","ye",2012,HORROR,"https://pra.com");
 //auto b1 = std::make_shared<Book>("ye", "ye", "ye", 2012, HORROR, "https://pra.com");
 //repo.addA(b1);
 //repo.addA(b1);
 //repo.delA(b1);
 //repo.displayAll();
 //repo.updateA(b1);
 //repo.displayAll();
    /*std::vector<int> test;
    int i;
    for (i = 0; i <= 4; i++)
        test.push_back(i);
    std::cout << test[0]<<std::endl;
    test[0] = 9;
    std::cout << test[0] << std::endl;*/

    /*std::string str;
    std::getline(std::cin,str);
    std::cout << str<<std::endl;*/

 
}
