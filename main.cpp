#include<stdio.h>
#include <math.h>
#include <gl/glut.h>
#include <cstdio>
#include <cstdlib>
#include <string>

#define KEY_ESC 27 // escape key ozel anahtari 

int fullEkran = 0; 
int FareBasilmisMi = 0;

float xrot = 15.0f; // x ve y ye gore rotation ilk degerleri 
float yrot = 150.0f;

float xdiff = 100.0f; //
float ydiff = 100.0f; // oteleme icin artilacak ve azaltilacak degerler ilk degeri 

float tra_x = 0.0f; // x e gore translate (oteleme) icin
float tra_y = 0.0f; // y e gore translate (oteleme) icin
float tra_z = 0.0f; // z e gore translate (oteleme) icin

float buyutKucult = 55.0f; // zoom miktar ilk degeri yuzde orani olarak dusunebiliriz 
float resize_f = 1.0f; // render edecegimiz seklin resize icin 

void printtext(float x, float y, std::string String) // ekran a bir string render etmek  icin fonksiyon
{
	glColor3f(1.0f, 1.0f, 1.0f); // beyaz RGB
	glMatrixMode(GL_PROJECTION); // matrisin modu ve depth (3D) testi yapmak 
	glPushAttrib(GL_DEPTH_TEST);
	glDisable(GL_DEPTH_TEST);
	glRasterPos2f(x, y); // iki boyut olmak uzere ve float tipinden bir kordinattan basla 
	for (int i = 0; i<String.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, String[i]); // stringi alip karakter karakter render ederiz 
	}
	glPopAttrib(); // testler ve render ettigimiz stringler daha belli bir sekilde ekranda gostermemiz icin 
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW); // tekrar model view olarak ayarla
	glPopMatrix();
}


void katmanlarCiz()
{


	glTranslatef(tra_x, tra_y, tra_z); // x  y ve z ye gore translate yapmak icin 

	glBegin(GL_QUADS); // quads (dortgen) render etmek uzere 4 nokta alip ondan sonra o dort arasinda bir dortgen cizer
	// 1.katman beyaz katman
	glColor3f(0.0f, 0.0f, 1.0f);


	// 1.katmanin ust kismi (top)
	glVertex3f(-0.5f, 0.75f, 0.9f); // 3 buyutlu bir nokta belirtmek icin 
	glVertex3f(0.5f, 0.75f, 0.9f);
	glVertex3f(0.5f, 0.75f, -0.9f);
	glVertex3f(-0.5f, 0.75f, -0.9f);
	// 1.katmanin on kismi (front)
	glVertex3f(-0.5f, 0.75f, 0.9f);
	glVertex3f(0.5f, 0.75f, 0.9f);
	glVertex3f(0.5f, 0.65f, 0.9f);
	glVertex3f(-0.5f, 0.65f, 0.9f);
	// 1.katmanin arka kismi (back)
	glVertex3f(-0.5f, 0.65f, -0.9f);
	glVertex3f(-0.5f, 0.75f, -0.9f);
	glVertex3f(0.5f, 0.75f, -0.9f);
	glVertex3f(0.5f, 0.65f, -0.9f);
	// 1.katmanin sol kismi (left)
	glVertex3f(-0.5f, 0.65f, 0.9f);
	glVertex3f(-0.5f, 0.75f, 0.9f);
	glVertex3f(-0.5f, 0.75f, -0.9f);
	glVertex3f(-0.5f, 0.65f, -0.9f);
	// 1.katmanin sag kismi (right)
	glVertex3f(0.5f, 0.65f, -0.9f);
	glVertex3f(0.5f, 0.75f, -0.9f);
	glVertex3f(0.5f, 0.75f, 0.9f);
	glVertex3f(0.5f, 0.65f, 0.9f);
	
	
	// 2. katman mavi katman
	glColor3f(0.258f, 0.945f, 0.956f);

	// 2.katmanin ust kismi (top)
	glVertex3f(-0.5f, 0.6f, 0.9f);
	glVertex3f(0.5f, 0.6f, 0.9f);
	glVertex3f(0.5f, 0.6f, -0.9f);
	glVertex3f(-0.5f, 0.6f, -0.9f);

	// 2.katmanin on kismi (front)
	glVertex3f(-0.5f, 0.6f, 0.9f);
	glVertex3f(0.5f, 0.6f, 0.9f);
	glVertex3f(0.5f, 0.5f, 0.9f);
	glVertex3f(-0.5f, 0.5f, 0.9f);
	// 2.katmanin arka kismi (back)
	glVertex3f(-0.5f, 0.5f, -0.9f);
	glVertex3f(-0.5f, 0.60f, -0.9f);
	glVertex3f(0.5f, 0.60f, -0.9f);
	glVertex3f(0.5f, 0.5f, -0.9f);
	// 2.katmanin sol kismi (left)
	glVertex3f(-0.5f, 0.5f, 0.9f);
	glVertex3f(-0.5f, 0.6f, 0.9f);
	glVertex3f(-0.5f, 0.6f, -0.9f);
	glVertex3f(-0.5f, 0.5f, -0.9f);
	// 2.katmanin sag kismi (right)
	glVertex3f(0.5f, 0.5f, -0.9f);
	glVertex3f(0.5f, 0.6f, -0.9f);
	glVertex3f(0.5f, 0.6f, 0.9f);
	glVertex3f(0.5f, 0.5f, 0.9f);



	// 3.katman yesil katman
	glColor3f(0.258f, 0.956f, 0.407f);

	// 3.katmanin ust kismi (top)
	glVertex3f(-0.5f, 0.45f, 0.9f);
	glVertex3f(-0.5f, 0.45f, -0.9f);
	glVertex3f(0.5f, 0.45f, -0.9f);
	glVertex3f(0.5f, 0.45f, 0.9f);

	// 3.katmanin on kismi (front)
	glVertex3f(-0.5f, 0.45f, 0.9f);
	glVertex3f(0.5f, 0.45f, 0.9f);
	glVertex3f(0.5f, 0.35f, 0.9f);
	glVertex3f(-0.5f, 0.35f, 0.9f);
	// 3.katmanin arka kismi (back)
	glVertex3f(-0.5f, 0.35f, -0.9f);
	glVertex3f(-0.5f, 0.45f, -0.9f);
	glVertex3f(0.5f, 0.45f, -0.9f);
	glVertex3f(0.5f, 0.35f, -0.9f);
	// 3.katmanin sol kismi (left)
	glVertex3f(-0.5f, 0.35f, 0.9f);
	glVertex3f(-0.5f, 0.45f, 0.9f);
	glVertex3f(-0.5f, 0.45f, -0.9f);
	glVertex3f(-0.5f, 0.35f, -0.9f);
	// 3.katmanin sag kismi (right)
	glVertex3f(0.5f, 0.35f, -0.9f);
	glVertex3f(0.5f, 0.45f, -0.9f);
	glVertex3f(0.5f, 0.45f, 0.9f);
	glVertex3f(0.5f, 0.35f, 0.9f);


	// 4.katman sari katman
	glColor3f(1.0f, 1.0f, 0.0f);
	
	glVertex3f(-0.5f, 0.3f, 0.9f);
	glVertex3f(-0.5f, 0.3f, -0.9f);
	glVertex3f(0.5f, 0.3f, -0.9f);
	glVertex3f(0.5f, 0.3f, 0.9f);

	// 4.katmanin on kismi (front)
	glVertex3f(-0.5f, 0.3f, 0.9f);
	glVertex3f(0.5f, 0.3f, 0.9f);
	glVertex3f(0.5f, 0.2f, 0.9f);
	glVertex3f(-0.5f, 0.2f, 0.9f);
	// 4.katmanin arka kismi (back)
	glVertex3f(-0.5f, 0.2f, -0.9f);
	glVertex3f(-0.5f, 0.3f, -0.9f);
	glVertex3f(0.5f, 0.3f, -0.9f);
	glVertex3f(0.5f, 0.2f, -0.9f);
	// 4.katmanin sol kismi (left)
	glVertex3f(-0.5f, 0.2f, 0.9f);
	glVertex3f(-0.5f, 0.3f, 0.9f);
	glVertex3f(-0.5f, 0.3f, -0.9f);
	glVertex3f(-0.5f, 0.2f, -0.9f);
	// 4.katmanin sag kismi (right)
	glVertex3f(0.5f, 0.2f, -0.9f);
	glVertex3f(0.5f, 0.3f, -0.9f);
	glVertex3f(0.5f, 0.3f, 0.9f);
	glVertex3f(0.5f, 0.2f, 0.9f);


	//  5.katman sari katman
	glColor3f(1.0f, 0.549f, 0.0f);
	
	glVertex3f(-0.5f, 0.15f, 0.9f);
	glVertex3f(-0.5f, 0.15f, -0.9f);
	glVertex3f(0.5f, 0.15f, -0.9f);
	glVertex3f(0.5f, 0.15f, 0.9f);

	// 5.katmanin on kismi (front)
	glVertex3f(-0.5f, 0.15f, 0.9f);
	glVertex3f(0.5f, 0.15f, 0.9f);
	glVertex3f(0.5f, 0.05f, 0.9f);
	glVertex3f(-0.5f, 0.05f, 0.9f);
	// 5.katmanin arka kismi (back)
	glVertex3f(-0.5f, 0.05f, -0.9f);
	glVertex3f(-0.5f, 0.15f, -0.9f);
	glVertex3f(0.5f, 0.15f, -0.9f);
	glVertex3f(0.5f, 0.05f, -0.9f);
	// 5.katmanin sol kismi (left)
	glVertex3f(-0.5f, 0.05f, 0.9f);
	glVertex3f(-0.5f, 0.15f, 0.9f);
	glVertex3f(-0.5f, 0.15f, -0.9f);
	glVertex3f(-0.5f, 0.05f, -0.9f);
	// 5.katmanin sag kismi (right)
	glVertex3f(0.5f, 0.05f, -0.9f);
	glVertex3f(0.5f, 0.15f, -0.9f);
	glVertex3f(0.5f, 0.15f, 0.9f);
	glVertex3f(0.5f, 0.05f, 0.9f);

	// 6.katman kirmizi katman
	glColor3f(0.9098f, 0.0f, 0.0f);

	glVertex3f(-0.5f, 0.0f, 0.9f);
	glVertex3f(-0.5f, 0.0f, -0.9f);
	glVertex3f(0.5f, 0.0f, -0.9f);
	glVertex3f(0.5f, 0.0f, 0.9f);

	// 6.katmanin on kismi (front)
	glVertex3f(-0.5f, 0.0f, 0.9f);
	glVertex3f(0.5f, 0.0f, 0.9f);
	glVertex3f(0.5f, -0.1f, 0.9f);
	glVertex3f(-0.5f, -0.1f, 0.9f);
	// 6.katmanin arka kismi (back)
	glVertex3f(-0.5f, -0.1f, -0.9f);
	glVertex3f(-0.5f, 0.0f, -0.9f);
	glVertex3f(0.5f, 0.0f, -0.9f);
	glVertex3f(0.5f, -0.1f, -0.9f);
	// 6.katmanin sol kismi (left)
	glVertex3f(-0.5f, -0.1f, 0.9f);
	glVertex3f(-0.5f, 0.0f, 0.9f);
	glVertex3f(-0.5f, 0.0f, -0.9f);
	glVertex3f(-0.5f, -0.1f, -0.9f);
	// 6.katmanin sag kismi (right)
	glVertex3f(0.5f, -0.1f, -0.9f);
	glVertex3f(0.5f, 0.0f, -0.9f);
	glVertex3f(0.5f, 0.0f, 0.9f);
	glVertex3f(0.5f, -0.1f, 0.9f);

	// 7.katman kirmizi katman
	glColor3f(0.564f, 0.0392f, 0.666f);

	glVertex3f(-0.5f, -0.15f, 0.9f);
	glVertex3f(-0.5f, -0.15f, -0.9f);
	glVertex3f(0.5f, -0.15f, -0.9f);
	glVertex3f(0.5f, -0.15f, 0.9f);

	// 7.katmanin on kismi (front)
	glVertex3f(-0.5f, -0.15f, 0.9f);
	glVertex3f(0.5f, -0.15f, 0.9f);
	glVertex3f(0.5f, -0.25f, 0.9f);
	glVertex3f(-0.5f, -0.25f, 0.9f);
	// 7.katmanin arka kismi (back)
	glVertex3f(-0.5f, -0.25f, -0.9f);
	glVertex3f(-0.5f, -0.15f, -0.9f);
	glVertex3f(0.5f, -0.15f, -0.9f);
	glVertex3f(0.5f, -0.25f, -0.9f);
	// 7.katmanin sol kismi (left)
	glVertex3f(-0.5f, -0.25f, 0.9f);
	glVertex3f(-0.5f, -0.15f, 0.9f);
	glVertex3f(-0.5f, -0.15f, -0.9f);
	glVertex3f(-0.5f, -0.25f, -0.9f);
	// 7.katmanin sag kismi (right)
	glVertex3f(0.5f, -0.25f, -0.9f);
	glVertex3f(0.5f, -0.15f, -0.9f);
	glVertex3f(0.5f, -0.15f, 0.9f);
	glVertex3f(0.5f, -0.25f, 0.9f);

	glEnd();
}

int init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // color buffer sifirla 

	glEnable(GL_DEPTH_TEST);// 3d goruntu icin 
	glDepthFunc(GL_LEQUAL); // depth comparision function incoming depth degeri eger stored depth vvalue kucuk veya esit ise 
	glClearDepth(1.0f); // depth bufferin clear degeri belirtiyor 

	return 1; 
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // hem color buffer hem de depth buffer temizle 
	glLoadIdentity(); // load matrix fonksiyonun ayni amacla kullanilir 

	gluLookAt( // her viewing transformation icin x y ve z degerleri
		0.0f, 0.0f, 3.0f, // eye 
		0.0f, 0.0f, 0.0f, // center
		0.0f, 1.0f, 0.0f); // up 

	glRotatef(xrot, 1.0f, 0.0f, 0.0f); // x e gore rotate yap 
	glRotatef(yrot, 0.0f, 1.0f, 0.0f); // y ye gore rotate yap 

	katmanlarCiz(); // tum render etmek istedigimiz sekiller display fonksiyon icinden cagirmali 
	printtext(-0.5, 0.70, "Su Seviyesi 24 C");
	printtext(-0.5, 0.55, "250 metre derinligi 19 C");
	printtext(-0.5, 0.40, "500 metre derinligi 15 C ");
	printtext(-0.5, 0.25, "750 metre derinligi 10 C ");
	printtext(-0.5, 0.10, "1000 metre derinligi 7 C ");
	printtext(-0.5, -0.05, "1500 metre derinligi 5 C ");
	printtext(-0.5, -0.2, "2000 metre derinligi 4 C");
	glFlush(); // execute glut commands 
	glutSwapBuffers(); // cift buffer kullandigimizda swap islemler kullanilmasi
}

void resize(int w, int h) // zoom in ve zoom out 
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h); // view port x,y alt sol kose width ve height olarak tanimlayan bor fonksiyon 

	gluPerspective(buyutKucult, resize_f * w / h, resize_f, 100 * resize_f); // fovy aspect z near ve z far olarak 

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void yardimciFonksiyon(int key, int x, int y) // H tusuna basinca prgramin secenekler gozuksun ekrana
{

	printf("U -----------> Saat Yonunde Dondur\n");
	printf("Y -----------> Saat Ters Yonunde Dondur\n");
	printf("W or w ------> Yukari\n");
	printf("S or s -----> Alt\n");
	printf("D or d ------> Sag\n");
	printf("A or a ------> Sol\n");
	printf("Z or z ------> Kucult\n");
	printf("X or x ------> Buyut\n");
	printf("Escape Butunu ---> Programi Sonlandir\n\n");

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // escape tusu
		exit(1);
		break;



	case 'w':
	case 'W':
		tra_x += 0.1f;
		break;
	case 's':
	case 'S':
		tra_x -= 0.1f;
		break;
	case 'a':
	case 'A':
		tra_z -= 0.1f;
		break;
	case 'd':
	case 'D':
		tra_z += 0.1f;
		break;
	case 'u':
	case 'U':
		xrot += 1.0f;
		yrot += 1.0f;
		xdiff += 1.0f;
		ydiff += 1.0f;
		break;

	case 'y':
	case 'Y':
		xrot -= 1.0f;
		yrot -= 1.0f;
		xdiff += 1.0f;
		ydiff += 1.0f;
		break;

	case 'h':
	case 'H':
		yardimciFonksiyon(key, x, y);
		break;
	case 'Z':
	case 'z':
		buyutKucult--;
		resize(1280, 920);

		break;
	case 'X':
	case 'x':
		buyutKucult++;
		resize(1280, 920);

		break;

	}


	glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y) // klavye ozel anahtarlar icin 
{
	if (key == GLUT_KEY_F1) // F1 butuna basina
	{
		fullEkran = !fullEkran;

		if (fullEkran){
			glutFullScreen();
			resize(1280, 920);
			
		}
			
		else
		{
			
			glutPositionWindow(350, 120); // ekran bizim bilgisayar ekranimizda nerede gozuksun 
		}
	}
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) // farenin sol tusu basilmissa
	{
		FareBasilmisMi = 1;

		xdiff = x - yrot; // o anki degerleri tut 
		ydiff = -y + xrot;
	}
	else
		FareBasilmisMi = 0;
}

void mouseMotion(int x, int y)
{
	if (FareBasilmisMi)
	{
		yrot = x - xdiff; // fare hareket ettiginde rotate degerleri degistir 
		xrot = y + ydiff;

		glutPostRedisplay(); // var olan pencereyi tekrar gorultele
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	
	glutInitWindowPosition(350, 60);
	glutInitWindowSize(1280, 920);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	//glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	
	glutCreateWindow("Bilgisayar Grafigi Soru 1 ");
	// tum yazdigimiz fonksyonlar hangi tur olaylardan belirtmek icin
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutReshapeFunc(resize);

	// eger gl ortan olusturmada bir hata olusursa
	if (!init())
		return 1;

	glutMainLoop(); // var olan olayi tekrarla 

	return 0;
}


