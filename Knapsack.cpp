#include <iostream>
#include <map>

using namespace std;

struct wt_profit
{
	int wt;
	int profit;
};

int main()
{
	int wt_arr[] = { 4, 2, 1, 6, 5, 4, 3 };
	int profit_arr[] = { 12, 4, 5, 14, 6, 1, 8 };

	//int wt_arr[] = {10,20,30};
	//int profit_arr[] = {60,100,120};

	const int bag_capacity = 17;

	multimap<float, wt_profit, greater<float> > profit_wt_ratio_map;
	wt_profit var;
	
	for ( int i=0; i<sizeof(wt_arr)/sizeof(wt_arr[0]); i++ )
	{
		var.wt = wt_arr[i];
		var.profit = profit_arr[i];
		profit_wt_ratio_map.insert(pair<float,wt_profit>( (float)profit_arr[i]/wt_arr[i] , var ));
	}

	multimap<float, wt_profit>::const_iterator itr = profit_wt_ratio_map.begin();

	int wt_sum = 0;
	float profit_sum = 0;

	cout << "\nWt Profit Structure: " << endl;

	for( ; itr != profit_wt_ratio_map.end(); itr++ )
	{
		wt_profit obj = static_cast<wt_profit>(itr->second);
		cout << "[" << itr->first << "; " << "(" << obj.wt << "," << obj.profit << ")" << "]" << endl;
	}

	cout << "\nWeights & Profits put are: " << endl;
	
	for(itr = profit_wt_ratio_map.begin() ; itr != profit_wt_ratio_map.end(); itr++ )
	{
		wt_profit obj = static_cast<wt_profit>(itr->second);

		if ( wt_sum >= bag_capacity ) break;
		else if ( (wt_sum + obj.wt) <= bag_capacity )	//take full object
		{
			wt_sum += obj.wt;
			float pr_fraction = obj.profit;
			profit_sum += pr_fraction;
			cout << "-(" << obj.wt << ", " << pr_fraction << ")" << endl;
		}
		else if ( (wt_sum + obj.wt) > bag_capacity )	//take a fraction of object
		{
			int diff = bag_capacity - wt_sum;
			float pr_fraction = (float)diff*(itr->first);
			wt_sum += diff;
			profit_sum += pr_fraction;
			cout << "+(" << diff << ", " << pr_fraction << ")" << endl;
			break;
		}
	}

	cout << "\nMaximum profit is: " << profit_sum << endl;

	return 0;
}

