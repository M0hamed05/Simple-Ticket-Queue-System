#include <iostream>
#include "clsQueueLine.h"
using namespace std;

int main()
{
	clsQueueLine PayBillsQueue("B0", 5);

	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();

	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintTicketsLineRTL();
	PayBillsQueue.PrintTicketsLineLTR();

	PayBillsQueue.PrintAllTickets();

	PayBillsQueue.ServeNewClient();

	PayBillsQueue.PrintInfo();
	PayBillsQueue.PrintAllTickets();
}
