#include <stdio.h>
void openAccount(double account[2][50])
{
   int empty = -1;
   for (int i = 0; i < 50; i++)
   {
      if (account[0][49 - i] == 0)
      {
         empty = 49 - i;
      }
   }
   if (empty == -1)
   {
      printf("there isnt room\n");
      return;
   }
   printf("please enter amount for deposit:\n");
   double amount = 0;
   if (scanf(" %lf", &amount) != 1)
   {
      printf("Faild to read to read the amount");
      return;
   }
   if (amount < 0)
   {
      printf("Invalid Amount");
      return;
   }
   account[0][empty] = 1;
   account[1][empty] = amount;
   empty += 901;
   printf("New accout number is: %d\n", empty);
}

void balanceInquiry(double account[2][50])
{
   printf("Please enter account number:");
   int num;
   if (scanf(" %d", &num) != 1)
   {
      printf("Failed to read the account number\n");
      return;
   }
   if (num < 901 || num > 950)
   {
      printf("Invalid account number\n");
      return;
   }
   else
   {
      int number = num - 901;
      if (account[0][number] != 1)
      {
         printf("This account is closed\n");
         return;
      }
      else
      {
         printf("The balance of account number %d is: %.2lf\n", num, account[1][number]);
         return;
      }
   }
}
void deposit(double account[2][50])
{
   printf("Please enter account number:");
   int num;
   if (scanf(" %d", &num) != 1)
   {
      printf("Failed to read the account number\n");
      return;
   }
   if (num < 901 || num > 950)
   {
      printf("Invalid account number\n");
      return;
   }
   else
   {
      int number = num - 901;
      if (account[0][number] != 1)
      {
         printf("This account is closed\n");
         return;
      }
      else
      {
         printf("Please enter the amount to deposit:");
         double amount;
         if (scanf(" %lf", &amount) != 1)
         {
            printf("Failed to read the amount\n");
            return;
         }
         else
         {
            if (amount < 0)
            {
               printf("Cannot deposit a negative amount\n");
               return;
            }
            account[1][number] += amount;
            printf("The new balance is: %.2lf\n", account[1][number]);
            return;
         }
      }
   }
}
void withdrawal(double account[2][50])
{
   printf("Please enter account number:");
   int num;
   if (scanf(" %d", &num) != 1)
   {
      printf("Failed to read the account number\n");
      return;
   }
   if (num < 901 || num > 950)
   {
      printf("Invalid account number\n");
      return;
   }
   else
   {
      int number = num - 901;
      if (account[0][number] != 1)
      {
         printf("This account is closed\n");
         return;
      }
      else
      {
         printf("Please enter the amount to withdraw:");
         double amount;
         if (scanf(" %lf", &amount) != 1)
         {
            printf("Failed to read the amount\n");
            return;
         }
         account[1][number] -= amount;
         printf("The new balance is: %.2lf\n", account[1][number]);
         return;
      }
   }
}
void closeAccount(double account[2][50])
{
   printf("Please enter account number:");
   int num;
   if (scanf(" %d", &num) != 1)
   {
      printf("Failed to read the account number\n");
      return;
   }
   if (num < 901 || num > 950)
   {
      printf("Invalid account number\n");
      return;
   }
   else
   {
      int number = num - 901;
      if (account[0][number] != 1)
      {
         printf("This account is already closed\n");
         return;
      }
      account[0][number] = 0;
      account[1][number] = 0;
      printf("Closed account number %d\n", num);
      return;
   }
}
void interest(double account[2][50])
{
   printf("Please enter interest rate:");
   int inter;
   if (scanf(" %d", &inter) != 1)
   {
      printf("Failed to read the interest rate\n");
      return;
   }
   if (inter < 0)
   {
      printf("Invalid interest rate");
      return;
   }
   else
   {
      for (int i = 0; i < 50; i++)
      {
         if (account[0][i] == 1)
         {
            account[1][i] = (account[1][i] / 100) * (100 + inter);
         }
      }
   }
}
void print(double account[2][50])
{
   for (int i = 0; i < 50; i++)
   {
      if (account[0][i] == 1)
      {
         printf("The balance of account number %d is: %.2lf\n", i + 901, account[1][i]);
      }
   }
   printf("\n");
   return;
}
void exit(double account[2][50])
{
   for (int i = 0; i < 50; i++)
   {
      account[0][i] = 0;
      account[1][i] = 0;
   }
   printf("\n");
   return;
}
