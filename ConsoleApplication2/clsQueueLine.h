#pragma once
#pragma warning(disable : 4996) 

#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

class clsQueueLine
{
private:

    string GetTimeAndDate()
	{
		time_t now = time(0);
		tm* local = localtime(&now);

		string result =
			to_string(1900 + local->tm_year) + "-" +
			to_string(1 + local->tm_mon) + "-" +
			to_string(local->tm_mday) + " " +
			to_string(local->tm_hour) + ":" +
			to_string(local->tm_min) + ":" +
			to_string(local->tm_sec);

		return result;
	}

	int _total_tickets = 0;
	string _prefix = "";
	int _served_clients = 0;
	int _waiting_clients = 0;
	int _taken_time = 0;
	

	struct client_info
	{
		string prefix;
		string time;
		int wating_clients;
		int serve_time;

	};

	queue <client_info> _clients_queue;
	queue<client_info> _temp;

public:
	client_info c;

	clsQueueLine(string prefix, int take_time)
	{
		_prefix = prefix;
		if (_taken_time < 0) take_time = 0;
		_taken_time = take_time;
	}

	void IssueTicket()	
	{
		_total_tickets++;

		c.prefix = _prefix + to_string(_total_tickets);
		c.time = GetTimeAndDate();
		c.wating_clients = _waiting_clients;
		c.serve_time = _waiting_clients * _taken_time;

		_waiting_clients++;
		_clients_queue.push(c);
	}

	void PrintInfo()
	{
		cout << "\n========================\n";
		cout << "\n\tQueue Info\n";
		cout << "\n========================\n";
		cout << "  Prefix = " << _prefix<<endl;
		cout << "  Total Tickets = " << _total_tickets<<endl;
		cout << "  Served Clients = "<<_served_clients << endl;
		cout << "  Wating Clients = "<<_waiting_clients << endl;
		cout << "========================\n";

	}

	void PrintTicket(client_info ticket)
	{
		cout << "\n_______________________\n";
		cout << "\n\t" << ticket.prefix << "\n\n";
		cout << "  " << ticket.time << endl;
		cout << "  Waiting Clients = " << ticket.wating_clients << "\n";
		cout << "   Service Time In\n\t" << ticket.serve_time << endl;
		cout << "\n_______________________\n";
	}

	void PrintTicketsLineRTL()
	{
		_temp = _clients_queue;
		cout << "\n Tickets : ";
		while (!_temp.empty()) {
			cout << _temp.front().prefix << " <---";
			_temp.pop();                
		}
	}

	void PrintTicketsLineLTR()
	{
		stack <client_info> stemp;
		_temp = _clients_queue;
		while (!_temp.empty()) {
			stemp.push(_temp.front());
			_temp.pop();
		}

		cout << "\n Tickets : ";
		while (!stemp.empty()) {
			cout << stemp.top().prefix << "---> ";
			stemp.pop();
		}
	}

	void PrintAllTickets()
	{
		_temp = _clients_queue;
		while (!_temp.empty())
		{
			PrintTicket(_temp.front());
			_temp.pop();
		}
	}

	void ServeNewClient()
	{
		if (_total_tickets > 0)
		{
			_clients_queue.pop();

			_total_tickets--;
			_served_clients++;
			_waiting_clients--;
		}
	}

	string WhoIsNext()
	{
		if (_clients_queue.empty()) return "No Clients Left.";
		else return _clients_queue.front().prefix;
	}

};

