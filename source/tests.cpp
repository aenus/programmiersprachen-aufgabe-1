#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <iostream>

double milesToKilometer(double miles){
    return miles*1.609344;
}



int checkPrime (int input){           
  if(input <2)
  {
  return false;
  } 
      for(int divider=2; divider<input; divider++){
        if(input%divider==0)
        return false;
      else 
        return true;
      }
}





long int bin (long int n, long int k)   
   {                                    
   long int i;
   long int nCr = 1;
 
   if (n <  0 || n > 20 || k < 0 || k > n) return (-1);
 
   if (k == 0 || k == n) return (nCr);
 
   for (i = 1; i <= k; i++)
      nCr = nCr * (n - i + 1) / i;
   return (nCr);
   }





double volume (double rad, double alt){   
  double volume = M_PI*rad*rad*alt;
  return volume;  
}
 double surface (double rad, double alt){    
  double surface = 2*M_PI*rad*rad*2*M_PI*rad*alt;
  return surface;
 }


double fract (double input){    
  while(input>1){               
    input = input -1;
  }
  return input;
}


long sumMultiples (){      
long sum = 0;
  for (int i=1; i<=1000; i++){
    if(i%3==0 || i%5==0){    
      sum += i;
    }  
  }
return sum;
}


long checksum (long input){     
    int sum =0;
        while (input>0){
            int n = input%10;
            sum += n;
            input -= m;
            input = input /10;
        }
return sum;
}


int gcd (int a ,int b){     
if (b==0)
  return a;
else
  return gcd(b, a%b);
}

TEST_CASE ("milesTest" , "[milesToKilometer]" )
{
  REQUIRE ( milesToKilometer (1) == 1.609344);
  REQUIRE ( milesToKilometer (100) ==160,9344);
}
TEST_CASE ("gcdTest" , "[gcd]" )
{
  REQUIRE ( gcd (2 ,6) == 3);
  REQUIRE ( gcd (9 ,12) == 3);
  REQUIRE ( gcd (24 ,36) == 12);
}
TEST_CASE ("checkSumTest" , "[checkSum]" )
{
  REQUIRE ( checksum (150598) == 28);
  REQUIRE ( checksum (191919) == 30);
  REQUIRE ( checksum (250417) == 19);
}
TEST_CASE ("sumMultiplesTest" , "sumMultiples" )
{
  REQUIRE ( sumMultiples () == 234168);
}
TEST_CASE ("fractTest" , "fract")
{
  REQUIRE(fract (7.5) == Approx(0.5));
}
TEST_CASE ("volTest" , "volume" )
{
  REQUIRE ( volume (4,5) == Approx (251.3274122872) );
}
TEST_CASE ("surfTest" , "surface" )
{
  REQUIRE ( surface (4,5) == Approx (226.195) );
}
TEST_CASE ("binTest" , "nCr" )
{
  REQUIRE ( nCr (10,3) == 120 );
  REQUIRE ( nCr (10,5) == 252 );
  REQUIRE ( nCr (10,0) == 1 );
}


TEST_CASE ("checkPrimetest" , "checkPrime" )
{
  REQUIRE ( checkPrime (1) == false );
  REQUIRE ( checkPrime (17) == true );
  REQUIRE ( checkPrime (6) == false );
  REQUIRE ( checkPrime (2) == true );
} 
int main(int argc, char* argv[])
{
  
  return Catch::Session().run(argc, argv);
}


