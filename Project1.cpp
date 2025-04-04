 #include <iostream>
 #include "clsQueueLine.h"

using namespace std;

int main()
{  
	clsQueueLine PayBillsQueue("A0", 10);

	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
 
	cout << "\nPay Bills Queue Info :\n\n";
 
	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintTicketsLineLTR();
	PayBillsQueue.PrintTicketsLineRTL();

	PayBillsQueue.PrintAllTickets();

 	system("pause>0");

	return 0;
}

 