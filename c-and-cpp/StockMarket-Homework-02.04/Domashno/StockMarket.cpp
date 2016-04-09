#include "iostream"
#include "fstream"
#include "vector"
#include "iomanip"
#include "string"
using namespace std;

struct Investors
{
	unsigned ID;
	char Name[30];
	double Capital;
};

struct Stocks
{
	unsigned InvestorID;
	unsigned CompanyID;
	double Shares;
};

struct Companies
{
	unsigned ID;
	char Name[30];
	double StockPrice;
};

void doesInvestorExist(unsigned invId, vector<Investors> &investorsList)
{
	bool exists = false;

	//moje da se napravi, kaot v uslovieto na cikala se sloji && !exists
	for (unsigned i = 0; i < investorsList.size() - 1; i++)
	{
		if (investorsList[i].ID == invId)
		{
			exists = true;
			break;
		}
	}

	if (!exists)
	{
		cout<<"ERROR"<<endl;
		exit(EXIT_FAILURE);
	}
}

void doesCompanyExist(unsigned compId, vector<Companies> &compList)
{
	bool exists = false;

	//moje da se napravi, kato v uslovieto na cikala se sloji && !exists vmeso break v if - a
	for (unsigned i = 0; i < compList.size() - 1; i++)
	{
		if (compList[i].ID == compId)
		{
			exists = true;
			break;
		}
	}

	if (!exists)
	{
		cout<<"ERROR"<<endl;
		exit(EXIT_FAILURE);
	}
}

int hasStocks(unsigned invId, unsigned compId, vector<Stocks> &stocks) 
{
	for (unsigned i = 0; i < stocks.size() - 1; i++)
	{
		if (stocks[i].InvestorID == invId && stocks[i].CompanyID == compId)
		{
			return i;
		}
	}

	return -1;
}

double sharesAvailable(Companies &comp, vector<Stocks> &stocks)
{
	double sum = 0;

	for (unsigned i = 0; i < stocks.size() - 1; i++)
	{
		if (stocks[i].CompanyID == comp.ID)
		{
			sum += stocks[i].Shares;
		}
	}

	double result = comp.StockPrice - sum;

	return result;
}

void buyStock(Investors &investor, Companies &company, vector<Stocks> &stocksList, double money)
{
	double investorCapital = investor.Capital;

	if (money > investorCapital || money <= 0)
	{
		cout<<"ERROR"<<endl;
		exit(EXIT_FAILURE);
	}

	double availableShares = sharesAvailable(company, stocksList);

	if (availableShares < money)
	{
		cout<<"ERROR"<<endl;
		exit(EXIT_FAILURE);
	}

	int isContained = hasStocks(investor.ID, company.ID, stocksList);

	if (isContained = -1)
	{
		Stocks stock;
		stock.InvestorID = investor.ID;
		stock.CompanyID = company.ID;
		stock.Shares = money;
		stocksList.push_back(stock);
	}
	else
	{
		stocksList[isContained].Shares += money;
	}

	investor.Capital -= money;

	cout<<"OK"<<endl;
}

void sellStock(Investors &investor, unsigned compID, vector<Stocks> &stocksList, double share)
{
	int hasShare = hasStocks(investor.ID, compID, stocksList);

	if (hasShare == -1 || share <= 0)
	{
		cout<<"ERROR"<<endl;
		exit(EXIT_FAILURE);
	}

	if (stocksList[hasShare].Shares < share)
	{
		cout<<"ERROR"<<endl;
		exit(EXIT_FAILURE);
	}

	stocksList[hasShare].Shares -= share;
	investor.Capital += share;

	cout<<"OK"<<endl;
}

double shareSum(unsigned invID, vector<Stocks> &stocks)
{
	double sum = 0;

	for (unsigned i = 0; i < stocks.size() - 1; i++)
	{
		if (stocks[i].InvestorID == invID)
		{
			sum += stocks[i].Shares;
		}
	}

	return sum;
}

void printInvestorInfo(Investors &investor, vector<Stocks> &stockList, vector<Companies> &companyList)
{
	double shares = shareSum(investor.ID, stockList);

	double overallCapital = shares + investor.Capital;

	ofstream outputFile;
	outputFile.open((string)investor.Name + ".txt", ios::out);

	outputFile<<investor.Name<<"\n\n";
	outputFile<<shares<<"\n\n";

	for (unsigned i = 0; i < stockList.size(); i++)
	{
		if (stockList[i].InvestorID == investor.ID)
		{
			unsigned compId = stockList[i].CompanyID;
			outputFile<<companyList[compId].Name;
			outputFile<<setw(15)<<"\t";
			outputFile<<stockList[i].Shares;
			outputFile<<"\n";
		}
	}
	outputFile<<"\n\n";

	outputFile<<setw(60);
	outputFile<<"Total: "<<overallCapital;

	outputFile.close();

	cout<<endl;
}

int main(int argc, char **argv) {

	vector<Stocks> stocksList;
	vector<Investors> investorsList;
	vector<Companies> companiesList;

	ifstream file;

	Investors investor;
	char investorFile[100];
	cin.getline(investorFile, 100);
	file.open(investorFile, ios::in | ios::binary);
	while(!file.eof())
	{
		file.read((char *) &investor, sizeof(Investors));
		investorsList.push_back(investor);
	}
	file.close();

	Companies company;
	char companyFile[100];
	cin.getline(companyFile, 100);
	file.open(companyFile, ios::in | ios::binary);
	while(!file.eof())
	{
		file.read((char *) &company, sizeof(Companies));
		companiesList.push_back(company);
	}
	file.close();

	Stocks stock;
	char stockFile[100];
	cin.getline(stockFile, 100);
	file.open(stockFile, ios::in | ios::binary);
	while(!file.eof())
	{
		file.read((char *) &stock, sizeof(Stocks));
		stocksList.push_back(stock);
	}
	file.close();

	char inputOpperation;
	cin>>inputOpperation;
	unsigned investorNum;
	cin>>investorNum;
	doesInvestorExist(investorNum, investorsList);

	switch (inputOpperation)
	{
	case 'b':
		{
			unsigned companyNum;
			cin>>companyNum;
			doesCompanyExist(companyNum, companiesList);
			double moneyToBuyWith;
			cin>>moneyToBuyWith;
			buyStock(investorsList[investorNum], companiesList[companyNum], stocksList, moneyToBuyWith);
			break;
		}
	case 's':
		{
			unsigned companyNum;
			cin>>companyNum;
			doesCompanyExist(companyNum, companiesList);
			double shareToSell;
			cin>>shareToSell;
			sellStock(investorsList[investorNum], companyNum, stocksList, shareToSell);
			break;
		}
	case 'p':
		{
			printInvestorInfo(investorsList[investorNum], stocksList, companiesList);
			break;
		}
	default:
		{
			cout<<"ERROR!"<<endl;
			exit(EXIT_FAILURE);
			break;
		}
	}

	exit(EXIT_SUCCESS);
}
