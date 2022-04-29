#include <bits/stdc++.h>
using namespace std;

int im = 3, ic = 3, fc = 0, fm = 0, flag = 0, status = 0, c = 0;

void print(char c1, char c2)
{
    int i;

    cout << endl;
    cout << endl;

    cout << "Step:- " << c << "::   ";

    for(i=0; i<im; i++){
        cout << "M" << " ";
    }
    for(i=0; i<ic; i++){
        cout << "C" << " ";
    }

    if(flag == 0)
    {
        cout << "   ----- LEFT_BANK->BOAT[" << c1 << "," << c2 << "] -----     ";
    }
    else
    {
        cout << "   ----- BOAT[" << c1 << "," << c2 << "]->RIGHT_BANK -----     ";
    }

    for(i=0; i<fm; i++){
        cout << "M" << " ";
    }
    for(i=0; i<fc; i++){
        cout << "C" << " ";
    }
}

int over()
{
    if(fm == 3 && fc == 3)
        return 1;
    else
        return 0;
}

void solve()
{
   while (over() == 0)
   {
       if(flag == 0)
       {
           switch(status)
           {
                case 1:
                    print('C', ' ');
                    ic++;
                    break;
                case 2:
                    print('C', 'M');
                    im++;
                    ic++;
                    break;
           }

           if((im-2 >= ic && fm+2 >= fc)|| (im-2 == 0))
           {
               im -= 2;
               status = 1;
               print('M', 'M');
               flag = 1;
               c++;
           }
           else if((ic-2 <= im && (fc+2 <= fm || fm == 0)) || im == 0)
           {
               ic -= 2;
               status = 2;
               print('C', 'C');
               flag = 1;
               c++;
           }
           else if((im-1 >= ic-1) && (fm+1 >= fc+1))
           {
               im--;
               ic--;
               status = 3;
               print('M', 'C');
               flag = 1;
               c++;
           }
       }

       else
       {
           switch(status)
           {
                case 1:
                    print('M', 'M');
                    fm += 2;
                    break;
                case 2:
                    print('C', 'C');
                    fc += 2;
                    break;
                case 3:
                    print('M', 'C');
                    fc++;
                    fm++;
                    break;
           }

           if(over() == 0)
           {
               if((fc>1 && fm==0) || im == 0)
               {
                   fc--;
                   status = 1;
                   print('C', ' ');
                   flag = 0;
                   c++;
               }
               else if((ic+1) > im)
               {
                   fc--;
                   fm--;
                   status = 2;
                   print('C', 'M');
                   flag = 0;
                   c++;
               }
           }
       }
   }
}

int main()
{
    print(' ',' ');
    solve();
    print(' ',' ');

    cout << endl;
    cout << endl;

    return 0;
}
