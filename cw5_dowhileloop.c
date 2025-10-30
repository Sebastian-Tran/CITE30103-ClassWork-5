#include <stdio.h>

int i;
int numOfCustomers;
int customerUnits;
float averageBill;
float highestBill;
float lowestBill;
float bill;


void main(){
	averageBill = 0;
	highestBill = 0;
	lowestBill = 0;

	printf("Enter a number of customers: \n");
	scanf("%d", &numOfCustomers);
	i = 0;
	do{
		printf("Enter the number of electricity units consumed for each customer(kWh): \n");
		scanf("%d", &customerUnits);
		
		if(customerUnits >= 0 && customerUnits <= 100){
			bill = customerUnits * 0.50;
		}
		else if(customerUnits >= 101 && customerUnits <= 300){
			bill = customerUnits * 0.75;
		}
		else if(customerUnits >= 301 && customerUnits <= 600){
			bill = customerUnits * 1.20;
		}
		else{
			bill = customerUnits * 1.50;
		}
		
		bill += 20.00; // add flat service charge
		
		if( bill > 500.00 ){
			bill *= 1.1;
		}

		averageBill += bill;
		
		if(highestBill == 0){
			highestBill = bill;
		}
		else if(bill > highestBill){ 
			highestBill = bill;
		}
		
		if(lowestBill == 0){
			lowestBill = bill;
		}
		else if(bill < lowestBill){
			lowestBill = bill;
		}
		printf("Total Bill for customer %d: $%.2f \n", i, bill);
		i++;
	}while(i < numOfCustomers);


	averageBill = (averageBill / numOfCustomers);

	printf("--- Billing Summary ---\n");
	printf("Average Bill: $%.2f\n", averageBill);
	printf("Highest Bill: $%.2f\n", highestBill);
	printf("Lowest Bill: $%.2f\n", lowestBill);
}
