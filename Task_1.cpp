#include <iostream>
using namespace std;

class MyBigInt
{
    int* big_int_;
    int int_length;

public:

    MyBigInt()
    {
        big_int_ = nullptr;
        int_length = 5;
        cout << "Constructor" << endl;
    }

    MyBigInt(int size)
    {
        int_length = size;
        big_int_ = new int[int_length];
        cout << "Constructor 2" << endl;
    }

    MyBigInt(const MyBigInt& obj)
    {
        int_length = obj.int_length;
        big_int_ = new int[int_length];

        for(int i=0; i<int_length; i++)
        {
            big_int_[i] = obj.big_int_[i];
        }
        cout << "Copy Constructor called" << endl;
     }

    void assign(const MyBigInt& obj)
    {
        int_length = obj.int_length;
        big_int_ = new int[int_length];

        for(int i=0; i<int_length; i++)
        {
            big_int_[i] = obj.big_int_[i];
        }
        cout << "Assign function" << endl;
    }

    int compare_to(const MyBigInt& obj)
    {
		int a;

		if (int_length == obj.int_length)
		{
            for(int i=0; i<int_length; i++)
            {
                if(big_int_[i] == obj.big_int_[i])
                {
			        a = 0;
                }
                else
			    {
                    a = 4;
                    break;
                }
            }
		}

		if (int_length < obj.int_length)
		{
			a = 1;
		}

		if (int_length < obj.int_length)
		{
			a = 2;
		}

		return a;
    }

    void display()
    {
        for(int i=0; i<int_length; i++)
        {
            cout << " " << big_int_[i] <<" ";
        }
        cout << endl;
    }

    void input()
    {
        cout << "Enter values of array" << endl;

        for(int i=0; i<int_length; i++)
        {
			cout << "Enter value at index " << i+1 << " : ";
            cin >> big_int_[i];
        }
        cout << endl;
    }

    ~MyBigInt()
    {
        if(big_int_ != nullptr)
        {
            delete []big_int_;
            big_int_ = nullptr;
            cout << "Destructor" << endl;

			system("pause");
        }
    }
};

int main()
{
    int size;

    cout << "Enter size of array : ";
    cin >> size;
	cout << endl;

    MyBigInt obj1;

    MyBigInt obj2(size);
    obj2.input();

    MyBigInt obj3=obj2;
    obj3.display();
    obj3.assign(obj2);
    obj3.display();

    int a = obj2.compare_to(obj3);

	if (a == 4)
	{
		cout << "After comparing the arrays the arrays have same size but different elements" << endl;
	}

	else
        cout << "After comparing the arrays the function returns : " << a << endl;

    return 0;
}