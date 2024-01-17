#include <iostream>
#include <vector>
#include <limits>
#include<string>
using namespace std;
int main() {
    int i = 0;
    int cost[] = {20, 40, 50};
    std::vector<std::pair<std::string, int>> arr;
    int totalItems = 0;
    int totalCost = 0;
    char product = 'A';

    while (i < 3) {
        int quantity;
        std::cout << "Please enter the quantity of product " << product << ":" ;
        std::cin >> quantity;
        arr.push_back(std::make_pair(std::string(1, product), quantity));
        product = static_cast<char>(product + 1);
        totalItems += quantity;
        totalCost += quantity * cost[i];
        i++;
    }

    int discount1 = 0;
    int discount2 = 0;
    int discount3 = 0;
    int discount4 = 0;
    string discount1name = "flat_10_discount" ;
    string discount2name = "bulk_5_discount" ;
    string discount3name = "bulk_10_discount" ;
    string discount4name = "tiered_50_discount" ;
    if( totalCost > 200 ) {
    discount1 = 10 ;
}
i = 0 ;
while( i < 3 ) {
    if( arr[ i ].second > 10 && discount2 != 0 ){
        discount2 = totalCost * 0.05 ;
    }
    if( arr[ i ].second > 20 && discount3 == 0  ){
        discount3 = totalCost * 0.1 ;
    }
    if( totalItems > 30 && arr[ i ].second > 15 ) {
        discount4 += ( 0.5 *  ((arr[ i ].second) - 15 ) ) ;
    }
    i++;
}

string finaldiscountname = "" ;
int maximum = max( discount1 , max( discount2 , max( discount3 , discount4))) ;
if(maximum == discount1 ) {
finaldiscountname = discount1name ;
}
if(maximum == discount2 ) {
    finaldiscountname = discount2name ;
}
if(maximum == discount3 ) {
    finaldiscountname = discount3name ;
}
if(maximum == discount4 ) {
    finaldiscountname = discount4name ;
}
if( maximum == 0 ) {
    finaldiscountname = "No Discount Applicable";
}
char ques ;
cout<<"Do you want to wrap this product ? (Y/N) :";
cin>>ques;
int gift = 0 ;
if( ques == 'y' || ques == 'Y') {
    gift++;
    totalCost++;
}

float shipping = ((float)(totalItems) / 10.0 ) *  5.0 ;
i = 0 ;
while( i < 3 ) {
cout<<arr[i].first<<" : "<<arr[ i ].second<<" "<<"Cost : "<<(arr[ i ].second * cost[ i ])<<endl;
i++;
}
cout<<"Total Cost :"<<totalCost<<endl ;
cout<<"Final Discount :"<<finaldiscountname<<" "<<maximum<<endl;
cout<<"Shipping :"<<shipping<<" "<<"Gift Wrap Fee :"<<gift<<endl;
cout<<"Total Amount :"<<(totalCost - maximum + shipping) ;
    return 0;
}
