//  Edwin Gonzalez
//  ITP 165, Spring 2016
//  Homework 03
//  edwingon@usc.edu
//
//  hw03.cpp
//  hw03
//
//  Created by Edwin Gonzalez on 1/29/16.
//  Copyright © 2016 Edwin Gonzalez. All rights reserved.
//

#include <iostream>
#include <string>

int main()
{
    //intializes the while loop
    
    bool done=true;
    
    while (done)
    {
    std::cout<<"Welcome to 165's version of the Myers-Briggs Personality Test."<<"\nAnswer each question with the answer that feels most correct."<<std::endl;
    std::cout<<"\nPlease answer using the following numbers and legend:"<<std::endl;
    std::cout<<"[1. YES 2. yes 3. uncertain 4. no 5. NO]"<<std::endl;
    
    const int numberOfQuestions=13;
    std::string questions[numberOfQuestions]=
    {
        "1. It is easy for you to communicate in social situations", //index
        "2. You are a person somewhat reserved and distanct in communication", //1
        "3. You enjoy having a wide circle of acquaintances", //2
        "4. After prolonged socializing you feel you need to get away and be alone", //3
        "5. You spend your lesiure time actively socializing with people, attending parties, shopping, etc.", //4
        "6. You find it difficult to speak loudly", //5
        "7. You rapidly get invloved in the social life of a new workplace", //6
        "8. Often you prefer to read a book than go to a party", //7
        "9. The more people speak you speak to, the better you feel", //8
        "10. You prefer to isolate yourself from the outside noises", //9
        "11. When with a group of people, you enjoy being directly involved and being at the center of attention", //10
        "12. You prefer to spend your leisure time alone or relaxing in a tranquil atmosphere", //11
        "13. You feel at ease in a crowd",//12
    };
    
    
    int userAnswers[numberOfQuestions];
    double result=0;
    
    for (int i=0; i<numberOfQuestions; i++)
    {
        std::cout<<questions[i]<<":";
        std::cin>>userAnswers[i];
        
            while (userAnswers[i]<1 || userAnswers[i]>5)
            {
                std::cout<<"Invalid option. Please insert a value between 1-5"<<std::endl;
                std::cout<<questions[i]<<":";
                std::cin>>userAnswers[i];
            }
        
    }

        //odd numbered questions
    
        for (int i=0; i<numberOfQuestions; i+=2)
        {
            
            if (userAnswers[i]==1)
            {
                result+=10;
            }
            else if (userAnswers[i]==2)
            {
                result+=5;
            }
            else if (userAnswers[i]==3)
            {
                result+=0;
            }
            else if (userAnswers[i]==4)
            {
                result-=5;
            }
            else
            {
                result-=10;
            }
            
        }
        
        //even numbered questions
        
        for (int i=1; i<numberOfQuestions; i+=2)
        {
            
            if (userAnswers[i]==1)
            {
                result-=10;
            }
            else if (userAnswers[i]==2)
            {
                result-=5;
            }
            else if (userAnswers[i]==3)
            {
                result+=0;
            }
            else if (userAnswers[i]==4)
            {
                result+=5;
            }
            else
            {
                result+=10;
            }
        }
        
        //This line of code displays the result number from the questions.
        //std::cout<<result<<std::endl;

        int final=0;
        
        if (result>0)
        {
            int final=(result/130)*100;
            std::cout<<"\nHere are your results:"<<std::endl;
            std::cout<<final<<"% Extrovert"<<std::endl;
        }
        else if (result==0)
        {
            int final=(result/130)*100;
        std::cout<<"\nHere are your results:"<<std::endl;
        std::cout<<"You are neither an extrovert or introvert"<<std::endl;
        }
        else
        {
            int final=(((-1*result)/130)*100);
            std::cout<<"\nHere are your results:"<<std::endl;
            std::cout<<final<<"% Introvert"<<std::endl;
        }
        
        
    std::string tryAgain;
   
    std::cout<<"\nWould you like to try again? (y/n)? ";
    std::cin>>tryAgain;
    
        //if the user types anything besides N or n it will the entire program will loop
        
    if (tryAgain=="N"||tryAgain=="n")
    {
        done=false;
        std::cout<<"\nQuitting..."<<std::endl;
    }

    }
    return 0;
}
