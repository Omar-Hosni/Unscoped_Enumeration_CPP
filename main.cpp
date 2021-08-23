#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

enum Direction {North, South, East, West};

string direction_to_string(Direction direction){
string result;

switch(direction){
case North:
    result = "North";
break;

case South:
    result = "South";
break;

case East:
    result = "East";
break;

case West:
    result = "West";
break;

default:
    result = "Unkown Direction";
break;
}
return result;
}

void test1(){
Direction direction {North};
cout<<"Direction "<<direction<<endl;
cout<<direction_to_string(direction)<<endl;

direction  = West;
cout<<"Direction "<<direction<<endl;
cout<<direction_to_string(direction)<<endl;

direction = Direction(100);
cout<<"Direction "<<direction<<endl;
cout<<direction_to_string(direction)<<endl;

direction = static_cast<Direction>(100);
cout<<"Direction "<<direction<<endl;
cout<<direction_to_string(direction)<<endl;
}


enum Grocery_Items{Milk, Bread, Apple, Orange};

ostream &operator<<(ostream &os, Grocery_Items grocery_item)
{

switch(grocery_item){

case Milk:
    os<<"Milk";
break;

case Bread:
    os<<"Bread";
break;

case Apple:
    os<<"Apple";
break;

case Orange:
    os<<"Orange";
break;

default:
    os<<"Invalid Item";
break;
}
return os;
}

bool is_valid_grocery_item(Grocery_Items grocery_item){
switch(grocery_item){
case Milk:
case Bread:
case Apple:
case Orange:
return true;

default:
    return false;
}
}

void display_grocery_list(const vector<Grocery_Items> &grocery_list){
int invalid_item_count{0};
int valid_item_count{0};

for(Grocery_Items item: grocery_list){

    cout<<item<<endl;
    if(is_valid_grocery_item(item))
        valid_item_count++;
    else
        invalid_item_count++;
}
cout<<"==============================="<<endl;
cout<<"Valid Items: "<<valid_item_count<<endl;
cout<<"Invalid Items: "<<invalid_item_count<<endl;
cout<<"Total Items: "<<valid_item_count + invalid_item_count<<endl;
}

void test2(){
vector<Grocery_Items> shopping_list;
shopping_list.push_back(Apple);
shopping_list.push_back(Apple);
shopping_list.push_back(Milk);
shopping_list.push_back(Orange);

int Helicopter{100};

shopping_list.push_back(Grocery_Items(Helicopter));
shopping_list.push_back(Grocery_Items(0));

display_grocery_list(shopping_list);
}

enum State {Engine_Failure, Inclement_Weather, Nominal, Unknown};
enum Sequence {Abort, Hold, Launch};

istream &operator>>(istream &is, State &state){

underlying_type_t<State> user_input;
is>>user_input;

switch(user_input){
case Engine_Failure:
case Inclement_Weather:
case Nominal:
case Unknown:
    state = State(user_input);
    break;

default:
    cout<<"User input is not a valid launch state"<<endl;
    state = Unknown;
}
return is;
}

void initiate(Sequence sequence){
    string result;
   switch(sequence){
   case Abort:
       result = "Abort";
    break;

   case Hold:
    result = "Hold";
    break;

   case Launch:
    result = "Launch";
    break;
   }
cout<<"Initiate "<<result<<" sequence!"<<endl;
}


void test3(){
State state;
cout<<"Launch state: ";
cin>>state;

switch(state){
case Engine_Failure:
case Unknown:
    initiate(Abort);
break;

case Inclement_Weather:
    initiate(Hold);
break;

case Nominal:
    initiate(Launch);
break;

}
}

int main()
{
    test3();
    return 0;
}
