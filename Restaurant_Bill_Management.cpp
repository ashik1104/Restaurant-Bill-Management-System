#include <bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];

protected:
    float total_tax;

public:
    Restaurant()
    {
        total_tax = 0;
    }

    void Total_tax(float tax)
    {
        this->total_tax += tax;
        // cout << "Total Tax : " << this ->total_tax << " Taka" << endl;
    }
};

int main()
{
    int n;
    cin >> n;

    Restaurant *order_and_bill = new Restaurant;

    for (int i = 0; i < n; i++)
    {

        cin >> order_and_bill->food_item_codes[i];
        cin.ignore();
        getline(cin, order_and_bill->food_item_names[i]);
        cin >> order_and_bill->food_item_prices[i];
    }
    cout << endl;

    cout << "                                      MAKE BILL" << endl;
    cout << "                        ------------------------------------" << endl;
    cout << "                        ------------------------------------" << endl;

    cout << "Item code\t\t"
         << "Item name\t\t\t\t"
         << "Item price" << endl;
    cout << "----------\t\t"
         << "-----------\t\t\t\t"
         << "----------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << order_and_bill->food_item_codes[i] << "\t\t\t";
        cout << order_and_bill->food_item_names[i] << "\t\t\t";
        cout << order_and_bill->food_item_prices[i] << endl;
    }
    cout << endl;

    while (true)
    {
        int table_no, number_of_items;
        cout << "Enter Table No : ";
        cin >> table_no;
        cout << "Enter Number of Items : ";
        cin >> number_of_items;

        int item_code[number_of_items];
        int item_quantity[number_of_items];

        for (int i = 0; i < number_of_items; i++)
        {
        Flag:
            cout << "Enter Item " << i + 1 << " Code : ";
            cin >> item_code[i];

            bool match = false;
            for (int j = 0; j < n; j++)
            {
                if (item_code[i] == order_and_bill->food_item_codes[j])
                {
                    match = true;
                    break;
                }
            }
            if (match == false)
            {
                cout << "This code is invalid. You need to enter the code again for item " << i + 1 << endl;
                goto Flag;
            }

            cout << "Enter Item " << i + 1 << " Quantity : ";
            cin >> item_quantity[i];
        }
        cout << endl;

        cout << "                                                       BILL SUMMARY" << endl;
        cout << "                                                 -------------------------" << endl;
        cout << "Table No. : " << table_no << endl;

        cout << "Item Code\t\t\t"
             << "Item Name\t\t\t"
             << "Item Price\t\t"
             << "Item Quantity\t\t"
             << "Total Price" << endl;
        cout << "---------\t\t\t"
             << "----------\t\t\t"
             << "----------\t\t"
             << "--------------\t\t"
             << "-----------" << endl;

        int get_it;
        int total_price[number_of_items];
        float tax = 0;
        for (int i = 0; i < number_of_items; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (item_code[i] == order_and_bill->food_item_codes[j])
                {
                    get_it = j;
                    break;
                }
            }
            total_price[i] = order_and_bill->food_item_prices[get_it] * item_quantity[i];
            cout << order_and_bill->food_item_codes[get_it] << "\t\t\t\t";
            cout << order_and_bill->food_item_names[get_it] << "\t\t";
            cout << order_and_bill->food_item_prices[get_it] << "\t\t\t";
            cout << item_quantity[i] << "\t\t\t";
            cout << total_price[i] << endl;
        }
        int sum_of_total_price = 0;
        for (int i = 0; i < number_of_items; i++)
        {
            sum_of_total_price += total_price[i];
        }
        tax = (sum_of_total_price * 5.0) / 100.0;
        float sum_with_tax = sum_of_total_price + tax;
        cout << "TAX\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << tax << endl;
        cout << "__________________________________________________________________";
        cout << "__________________________________________________________________" << endl;
        cout << "NET TOTAL\t\t\t\t\t\t\t\t\t\t\t\t\t" << sum_with_tax << " Taka" << endl;

        // order_and_bill ->Total_tax(tax);
        cout << endl;
    }
}
