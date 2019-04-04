#include <iostream>
using namespace std;
void Brezenhem(char **z, int x0, int y0, int x1, int y1)
{
  int A, B, sign;
  A = y1 - y0;
  B = x0 - x1;
  if (abs(A) > abs(B)) sign = 1;
  else sign = -1;
  int signa, signb;
  if (A < 0) signa = -1;
  else signa = 1;
  if (B < 0) signb = -1;
  else signb = 1;
  int f = 0;
  z[y0][x0] = '*';
  int x = x0, y = y0;
  if (sign == -1)
  {
    do {
      f += A*signa;
      if (f > 0)
      {
        f -= B*signb;
        y += signa;
      }
      x -= signb;
      z[y][x] = '*';
    } while (x != x1 || y != y1);
  }
  else
  {
    do {
      f += B*signb;
      if (f > 0) {
        f -= A*signa;
        x -= signb;
      }
      y += signa;
      z[y][x] = '*';
    } while (x != x1 || y != y1);
  }
}
int main()
{
  const int SIZE = 25; // размер поля
  int x1, x2, y1, y2;
  char **z;
  z = new char*[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    z[i] = new char[SIZE];
    for (int j = 0; j < SIZE; j++)
      z[i][j] = '-';
  }
  cout << "x1 = ";     cin >> x1;
  cout << "y1 = ";     cin >> y1;
  cout << "x2 = ";     cin >> x2;
  cout << "y2 = ";    cin >> y2;
  Brezenhem(z, x1, y1, x2, y2);
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
      cout << z[i][j];
    cout << endl;
  }
  cin.get(); cin.get();
  return 0;
}










char *put_points(char *str, int count)
{
	while(count > 0)
	{
		str[count] = '.';
		count--;
	}
	return (str);
}

void print_map(char **map, int size)
{
	int i = 0;
	int j;

	while(i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
		++i;
	}
	ft_putchar('\0');
}

void draw_line(char **map, int x1, int y1, int x2, int y2)
{
	int a = y2 - y1;
	int b = x1 - x2;
	float c = y1*x2 + y2*x1;



}

int main()
{
	int map = 25;
	char **arr_map;
	int i = 0;

	arr_map = (char **)malloc(sizeof(char *) * (map + 1));
	while(i < map)
	{
		arr_map[i] = (char *)malloc(sizeof(char) * (map + 1));
		arr_map[i] = put_points(arr_map[i], map);
		i++;
	}
	drawCircle(4, 4, 9);

	print_map(arr_map, map);
	return (0);
}

