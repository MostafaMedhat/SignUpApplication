#include <iostream>
#include <string>
#include <array>
#include <vector>
constexpr int USER_NUMBER = 100;
 enum  class options 
    {
    UNDEFINED = 0,    
    APPEND = 1,
    FETCH = 2,
    QUIT =3,
    NUM_OF_OPTIONS =4
    };
    //overloading options to input stream
    std::istream& operator>>(std::istream &inputStream, options &result)
    {
        int optionNum;
        inputStream>>optionNum;
        result = static_cast<options>(optionNum);
        return inputStream;
    }   
class USER
{
private :
    
    // save user name
    std::vector<std::string> username ={};
    // save user age
    std::vector<int> age{};
    std::vector<int> id{};
    options optionSelect; 
    int user_id = 0;
    int SelectedOption;
    void appendHandler()
    {
        std::string UserName;
        int age;
        std::cout<< " Add User. Please enter user name and age"<<"\n";
        std::cout<< " Name : ";
        std::getline(std::cin>>std::ws, UserName);
        std::cout<<"\n" <<" Age : ";
        std::cin>> age;
        AddRecord(UserName,age);
    }
    void fetchHanlder()
    {
        int user_id;
        std::cout <<" Please enter user id " ;
        std::cin>>user_id;
        FetchRecord(user_id);

    }
      void AddRecord(std::string user, int userage)
    {
        //check for the user insertion 
        if (user_id <= USER_NUMBER)
        {
           
            username.push_back(user);
            age.push_back(userage);
            id.push_back(user_id);
            std::cout <<"User added sucessgully with ID = "<< user_id<<"\n";
            user_id++;   
        }
        else
        {
            std::cout<<"Excced Maximum limit of users = " << USER_NUMBER<<"\n";
        }
    }
    void FetchRecord(int fetchID)
    {
        if(fetchID< user_id)
        {
        std::cout<<" User ID : "<<id[fetchID]<<"\n";
        std::cout<<" User Name : "<<username[fetchID]<<"\n";
        std::cout<<" Age : "<<age[fetchID]<<"\n";
        }
        else
        {
            std::cout<< " ID is not exist , please enter valid ID"<<"\n";
        }
       

    }
public:
   
  
    void showWelcomeApp()
    {
        std::cout<< " User Sign Up Application"<<"\n";
    }
    void showOptions()  
    {
        std::cout<<" Please select an option"<<"\n";
        std::cout<<" 1.Add Record"<<"\n";
        std::cout<<" 2.Fetch Record"<<"\n";
        std::cout<<" 3.Quit"<<"\n";
        
    }
    void selectOptions()
    {
        std::cout << " Enter Option :";
        std::cin >> optionSelect;
        if((optionSelect== options::UNDEFINED)||
            (optionSelect>options::NUM_OF_OPTIONS))
        {
            std::cout<<" Option not exist"<<"\n";
        }
        else
        {
            //do nothing
        }
    }
    void optionControl()
    {
        switch (optionSelect)
        {
        case options::APPEND:
            // append Handler 
            appendHandler();
            break;
        case options::FETCH:
            //fetch handler
            fetchHanlder();
            break;
        case options::QUIT:
            std::cout<< " Program Exit"<<"\n";
            exit(0);
            //Quit handler
            break;    
        default:
            break;
        }
    }

};
int main()
{   
class USER userAccess;

userAccess.showWelcomeApp();
while(1)
{
userAccess.showOptions();
userAccess.selectOptions();
userAccess.optionControl(); 
}

return 0;
}