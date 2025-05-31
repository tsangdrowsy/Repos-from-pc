#include<stdio.h>
struct Hocsinh
{
	char maso[11], Ho[11], ten[51];
	int phai, namsinh;
};
#define MAX 50
struct lophoc
{
	Hocsinh aHocsinh[MAX];
	int soluong;
};
void NhapLopHoc(lophoc& lop)
{
	printf("Nhap so luong hoc sinh: ");
	scanf("%d", &lop.soluong);
	while (lop.soluong <= 0 || lop.soluong > MAX)
	{
		printf("Nhap lai");
		scanf("%d", lop.soluong);
	}
	for (int i = 0; i <= lop.soluong; i++)
	{
		printf("Nhap thong tin hoc sinh %d: \n", i);
		printf("+ Ma so: ");
		flushall(); gets_s(lop.aHocsinh[i].maso);
		printf("+ Ho lot: ");
		flushall(); gets_s(lop.aHocsinh[i].Ho);
		printf("+ Ten: ");
		flushall(); gets_s(lop.aHocsinh[i].ten);
		printf("+ Phai: ");
		scanf("%d", &lop.aHocsinh[i].phai);
		while (lop.aHocsinh[i].phai != 0 && lop.aHocsinh[i].phai != 1)
		{
			printf("+ Nhap sai! Nhap lai: ");
			scanf("%d", &lop.aHocsinh[i].phai);
		}
		printf("+ Nam sinh: ");
		scanf("%d", &lop.aHocsinh[i].namsinh);
		while (lop.aHocsinh[i].namsinh <= 0)
		{
			printf("+ Nhap sai! Nhap lai: ");
			scanf("%d", &lop.aHocsinh[i].namsinh);
		}
	}
}
void XuatLopHoc(lophoc & lop)
{
	printf("Lop hoc co %d hoc sinh: \n", lop.soluong);
	printf("STT\tMa so\tHo ten\t\tPhai\tNam sinh \n");
	for (int i = 0; i <= lop.soluong - 1; i++)
	{
	printf("%d\t%s\t%s %s\t", i + 1, lop.aHocsinh[i].maso,
		lop.aHocsinh[i].Ho, lop.aHocsinh[i].ten);
		if (lop.aHocsinh[i].phai == 1)
		printf("Nam\t");
		else
		printf("Nu\t");
		printf("%d", lop.aHocsinh[i].namsinh);
		printf("\n");
	}
}
void DemSiSo(lophoc lop, int& sonam, int& sonu)
{
	sonam = sonu = 0;
	for (int i = 0; i <= lop.soluong - 1; i++)
	{
		if (lop.aHocsinh[i].phai == 1)
			sonam++;
		else
			sonu++;
	}
}
void SapXepTangTheoNamSinh(lophoc& lop)
{
	for (int i = 0; i <= lop.soluong - 2; i++)
		for (int j = i + 1; j <= lop.soluong - 1; j++)
		{
			if (lop.aHocsinh[i].namsinh > lop.aHocsinh[j].namsinh)
			{
				Hocsinh tmp = lop.aHocsinh[i];
				lop.aHocsinh[i] = lop.aHocsinh[j];
				lop.aHocsinh[j] = tmp;
			}
		}
}
int main()
{
	lophoc lop =
	{
		{
			{"01","Nguyen Van","A",1,1984},
			{"02","Tran Thi","B",0,1982},
			{"03","Le Duy","C",1,1982}
		},
		3
	};
	lophoc lop;
	int sonam, sonu;
	XuatLopHoc(lop);
	DemSiSo(lop, sonam, sonu);
	printf("+ Dem si so hoc sinh trong lop hoc: \n");
	printf("Lop co %d hoc sinh, trong do %d nam va %d nu.\n", lop.soluong, sonam,
		sonu);
	printf("+ Danh sach hoc sinh trong lop hoc tang dan theo nam sinh:\n");
	SapXepTangTheoNamSinh(lop);
	XuatLopHoc(lop);
	return 0;
}