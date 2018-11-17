#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
	ifstream input("nanobot.inp");
	ofstream output;

   int N, K, P, Q, R, x = 0, y = 0, v = 1, w = 1, count = 1, flag = 1, i = -1, j = -1;
   input >> N >> K >> P >> Q >> R;
   while (!(v == P && w == Q)) {

      if (count == R) {
         i = v;
         j = w;
      }
      
      if (flag == 1) {
         w++;
         count++;
         if (w == K - y)
            flag++;
      }
      
      else if (flag == 2) {
         v++;
         count++;
         if (v == N - x)
            flag++;
      }
      
      else if (flag == 3) {
         w--;
         count++;
         if (w == x + 1)
            flag++;
      }
      
      else {
         v--;
         count++;
         if (v == x + 2) {
            x++;
            y++;
            flag = 1;
         }
      }
   }

   output << count << endl;
   if (i == -1) {
      while (count != R) {
         if (flag == 1) {
            w++;
            count++;
            if (w == K - y)
               flag++;
         }
         else if (flag == 2) {
            v++;
            count++;
            if (v == N - x)
               flag++;
         }
         else if (flag == 3) {
            w--;
            count++;
            if (w == x + 1)
               flag++;
         }
         else {
            v--;
            count++;
            if (v == x + 2) {
               x++;
               y++;
               flag = 1;
            }
         }
      }
      i = v;
      j = w;
   }

   output << i << ' ' << j << endl;
   return 0;
}