# How to compile 
1- g++ SingUp.cpp -o SingUp 
# How to Run 
1- ./SingUp


# SignUpApplication
Project Requirements: Sign-Up Application
we’re going to be writing a user registration application. This will allow users to register with the system, providing both their name and age, and we’ll store this information in our own custom type. We’ll also provide the ability for a user to be looked up by an ID, retrieving their information.


#**Here are the steps to complete the activity:**

userAccess.showWelcomeApp() : show welcome meesage ;
while(1) // make the program running all times can be quit if the user request quit 
{
userAccess.showOptions(); // show options for the user 1 - Add record , 2- Fetch Record ,3- Quit 
userAccess.selectOptions(); // select one of the above option
userAccess.optionControl(); // execute handler for each option to reach the program goal 
}

 

Please Note that Max numbers of records will be 100 only ( use it for your array declaration ).

