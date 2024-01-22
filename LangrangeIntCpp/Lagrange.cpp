#include <iostream>
#include <vector>

template<typename T>
static double LangrangeInt(double& x, std::vector<T>& xData, std::vector<T>& yData)
{
	int n = xData.size();
	T result = 0;
	for (int i=0; i<n;i++)
	{
		T term = yData[i];
		for (int j=0; j<n;j++)
		{
			if (i != j)
			{
				term *= (x - xData[j]) / (xData[i]-xData[j]);
			}
		}
		result += term;
	}
	return result;
}

int main()
{
	//It works, but to plot anything I would need to use ROOT, and I don't wanna do that right now, so screw it.
	double x = 2.0;
	std::vector<double> xData = { 1.0,2.0,3.0 };
	std::vector<double> yData = { 2.0,2.2,2.3 };

	auto resultado = LangrangeInt(x, xData, yData);

	std::cout << resultado << "\n";
}