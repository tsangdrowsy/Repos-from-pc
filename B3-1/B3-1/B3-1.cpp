#include<stdio.h>
#include<math.h>

typedef struct tagPhanSo
{
	int tuSo;
	int mauSo;
}
Phanso;
void NhapPhanSo(const char* info, Phanso& ps);
int SoSanhPhanSo(Phanso p1, Phanso p2);
void CongPhanSo(Phanso p1, Phanso p2, Phanso& pret) {
	pret.tuSo = p1.tuSo * p2.mauSo + p1.mauSo * p2.tuSo;
	pret.mauSo = p1.mauSo * p2.mauSo;
	RutGonPhanSo(pret);
}
int main()
{
	Phanso p1, p2;

	NhapPhanSo("Moi ban nhap phan so 1: ", p1);
	NhapPhanSo("Moi ban nhap phan so 2: ", p2);
	RutGonPhanSo(p1); RutGonPhanSo(p2);
	printf("+ Rut gon: ");
	XuatPhanSo(p1); printf(" ");
	XuatPhanSo(p2); printf("\n");

	char aDau[3] = { '<','=','>' };
	int ret = SoSanhPhanSo(p1, p2);

	printf("+ So Sanh: ");
	XuatPhanSo(p1);
	printf("%c", aDau[ret + 1]);
	XuatPhanSo(p2);
	printf("\n");
	Phanso pret;
	CongPhanSo(p1, p2, pret);
	printf("+ Cong: ");
	XuatPhanSo(p1); printf("+");
	XuatPhanSo(p2); printf("=");
	XuatPhanSo(pret); printf("\n");
	return 0;
}
void NhapPhanSo(const char* info, Phanso& ps)
{
	printf("%s", info);
	scanf("%d%d", &ps.tuSo, &ps.mauSo);
}
void XuatPhanSo(Phanso ps)
{
	printf("[%d/%d]", ps.tuSo, ps.mauSo);
}
void RutGonPhanSo(Phanso& ps)
{
	int ucln, a, b, tmp;
	a = ps.tuSo;
	b = ps.mauSo;
	while (b != 0)
	{
		tmp = a;
		a = b;
		b = tmp % a;
	}
	ucln = a;
	ps.tuSo = ps.tuSo / ucln;
	ps.mauSo = ps.mauSo / ucln;
}
int SoSanhPhanSo(Phanso p1, Phanso p2)
{
	int ret;
	p1.tuSo = p1.tuSo * p1.mauSo / abs(p1.mauSo);
	p1.mauSo = abs(p1.mauSo);
	p2.tuSo = p2.tuSo * p2.mauSo / abs(p2.mauSo);
	p2.mauSo = abs(p2.mauSo);
	int vp1 = p1.tuSo * p2.mauSo;
	int vp2 = p2.tuSo * p1.mauSo;
	if (vp1 > vp2)
		ret = 1;
	else if (vp1 == vp2)
		ret = 0;
	else
		ret = -1;
	return ret;
}

