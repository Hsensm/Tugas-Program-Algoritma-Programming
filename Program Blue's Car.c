#include <stdio.h>
#include <string.h>
int main (){
	int Year, i;
	double Cost;
	char Wait;
	char CarType[200];
	char Title [] = "Blue's Car";
	char Title2 [] = "=======================";
	char Title3 [] = "Please Wait.....";
	
	printf("%40s\n", Title);
	printf("%46s\n\n\n", Title2);
	printf("Welcome to Blue's Car Price Simulator\n");
	printf("Today's Date : October 31th 2016\n\n");
	
	    do {
        printf("Please input your car type [2..20] : ");
        scanf("%s", CarType);

        int len = strlen(CarType);

        if (len >= 2 && len <= 20) { 
		break;
    } 
}
	while (1);
	
	printf("\n");
	do {
	printf("*we cannot buy 1 year old car :)\n");
	printf("Please input purchasing year of the car [2000 - 2014]: ");
	scanf("%d", &Year);
	printf("\n");
	
	if (Year >= 2000 && Year <= 2014){
		break;
	}
}	
while (1);

do {
	printf("Please input price of the car when it was purchased in %d [100.000.000 - 300.000.000] : ", Year);
	scanf("%lf", &Cost);														//di soal file word ditulis 10.000.000 sampai 300.000.000 untuk harga mobil
	
	if (Cost >= 100000000 && Cost <= 300000000){								//tapi di soal file command prompt 100.000.000 sampai 300.000.000
		break;																
	}																			//jadi saya mengikuti yang ada di command prompt saja takut di soal word typo
}
while (1);
printf("\n");
printf("%43s\n", Title3);
getchar();
getchar();

printf("These are the info of your %s car with Rp. %.0lf price\n", CarType, Cost);
double j = 0.0;
int YearsOld = 2016 - Year;
for (i = YearsOld-1; i >= 0; i--){
	int CarOld = 2016 - i;
	double BaseRate = 10.0;
	double Rate = BaseRate - j*2.0;
	j = j + 1.0;
	if (Rate < 4.0){
		Rate = 4.0;
	}
	double PriceRed = Cost - (Cost * Rate/100.0);
	Cost = PriceRed;
	printf("In %d Car Price = Rp. %.0lf, because of %.0lf%% Price reduction \n", CarOld, PriceRed, Rate);
}
printf("\n\n");
if (YearsOld >= 5){
	printf("Before selling, your car need maintenance\n");
}
else printf ("Your car condition still ok\n");
	return 0;
}
