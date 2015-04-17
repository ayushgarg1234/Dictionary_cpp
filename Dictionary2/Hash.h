 using namespace std;

class hashing{
public:
	int hash_compression_map2(unsigned int hvalue);
	unsigned int hash_code_map(string a);
	int hash_compression_map(unsigned int hvalue, int m);
};

int hashing::hash_compression_map2(unsigned int hvalue)
{
	double A = (pow(5, 0.5) - 1) / 2;
	double k = double(hvalue);
	int h = int(3-(fmod(k,3)));
	return h;
}

unsigned int hashing::hash_code_map(string a)
{
	unsigned int hvalue = 0;
	for (unsigned int i = 0; i < a.length(); i++)
	{
		hvalue = hvalue + (int(a[i]))*pow(33, i);
		i++;
	}
	return hvalue;
}

int hashing::hash_compression_map(unsigned int hvalue,int m)
{
	double A = (pow(5,0.5)-1)/2;
	double k = double(hvalue);
	double md = double(m);
	int h = int(md*(fmod((k*A), (double)1)));
	return h;
}

