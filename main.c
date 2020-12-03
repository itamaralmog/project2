#include <stdio.h>
#include "myBank.h"
enum bool
{
   false,
   true
};
int main()
{
   double account[2][50];
   int running = true;
   for (int i = 0; i < 50; i++)
   {
      account[0][i] = 0;
      account[1][i] = 0;
   }
   while (running)
   {
      printf("\nplease choose a transaction type:\n");
      printf(" O-Open Account\n");     
      printf(" B-Balance Inquiry\n");
      printf(" D-Deposit\n");
      printf(" W-Withdrawal\n");
      printf(" C-Close Account\n");
      printf(" I-Interest\n");
      printf(" P-Print\n");
      printf(" E-Exit\n");

      char c = 0;
      if (scanf(" %c", &c) != 1)
      {
         printf("Invalid transaction type");
      }
      switch (c)
      {
      case 'O':
         openAccount(account);
         break;
      case 'B':
         balanceInquiry(account);
         break;
      case 'D':
         deposit(account);
         break;
      case 'W':
         withdrawal(account);
         break;
      case 'C':
         closeAccount(account);
         break;
      case 'I':
         interest(account);
         break;
      case 'P':
         print(account);
         break;
      case 'E':
         exit(account);
         running = false;
         break;
      default:
         printf("Invalid transaction type\n");
         break;
      }
   }
   return 0;
}
