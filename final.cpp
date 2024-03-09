#include "iGraphics.h"
#include <math.h>
#include <stdlib.h>


int console_x = 1350;
int flag;

int console_y = 650;
double h_par[50], k_par[50] = {50}, p_par[50] = {0};
double Ox = console_x / 2.0;
double Oy = console_y / 2.0;
char str[100], str2[100], str3[100];
int len;
int num_lines = 0, num_quad_curves = 0, num_expo_curves_1 = 0, num_expo_curves_2 = 0, num_expo_curves_3 = 0, num_expo_curves_4 = 0, num_circles = 0, num_parabolas = 0, num_ellipses = 0, num_hyperbolas = 0, num_hyperbolas2 = 0;
int color;
int darkmode = 0;
int title_screen = 1;
int mode;

int flag11 = 0, flag12 = 0, flag13 = 0, flag14 = 0, flag15 = 0, flag16 = 0, flag17 = 0;
int flag111 = 0, flag112 = 0, flag113 = 0;
int flag121 = 0, flag122 = 0, flag123 = 0;
int flag131 = 0, flag132 = 0, flag133 = 0, flag134 = 0;
int flag1311 = 0, flag1312 = 0;
int flag1321 = 0, flag1322 = 0;
int flag1331 = 0, flag1332 = 0;
int flag1341 = 0, flag1342 = 0;
int flag141 = 0, flag142 = 0, flag143 = 0, flag144 = 0;
int flag151 = 0, flag152 = 0;
int flag161 = 0, flag162 = 0, flag163 = 0, flag164 = 0, flag165 = 0, flag166 = 0;
int flag171 = 0, flag172 = 0, flag173 = 0, flag174 = 0, flag175 = 0, flag176 = 0;

double d, e, a, b, diff_x = 0, diff_y = 0, x_beginning1, x_beginning2, y_beginning1, y_beginning2;
double slope, y_incept, xlow, xhigh, a_, b_;
int count = 0;
// int num_grids = 5000;
int num_grids = 10000;
int num_log1 = 0, num_log2 = 0;
int num_trig_sin = 0, num_trig_cos = 0, num_trig_tan = 0, num_trig_cosec = 0, num_trig_sec = 0, num_trig_cot = 0;
int inum_trig_sin = 0, inum_trig_cos = 0, inum_trig_tan = 0, inum_trig_cosec = 0, inum_trig_sec = 0, inum_trig_cot = 0;

double log_k_1[50] = {0}, log_a_1[50] = {0}, log_b_1[50] = {0}, log_c_1[50] = {0};
double log_kk[50] = {0}, log_aa[50] = {0}, log_bb[50] = {0}, log_cc[50] = {0};

double sin_k_1[50] = {0}, sin_a_1[50] = {0}, sin_b_1[50] = {0}, sin_c_1[50] = {0};
double cos_k_1[50] = {0}, cos_a_1[50] = {0}, cos_b_1[50] = {0}, cos_c_1[50] = {0};
double tan_k_1[50] = {0}, tan_a_1[50] = {0}, tan_b_1[50] = {0}, tan_c_1[50] = {0};
double cosec_k_1[50] = {0}, cosec_a_1[50] = {0}, cosec_b_1[50] = {0}, cosec_c_1[50] = {0};
double sec_k_1[50] = {0}, sec_a_1[50] = {0}, sec_b_1[50] = {0}, sec_c_1[50] = {0};
double cot_k_1[50] = {0}, cot_a_1[50] = {0}, cot_b_1[50] = {0}, cot_c_1[50] = {0};

double isin_k_1[50] = {0}, isin_a_1[50] = {0}, isin_b_1[50] = {0}, isin_c_1[50] = {0};
double icos_k_1[50] = {0}, icos_a_1[50] = {0}, icos_b_1[50] = {0}, icos_c_1[50] = {0};
double itan_k_1[50] = {0}, itan_a_1[50] = {0}, itan_b_1[50] = {0}, itan_c_1[50] = {0};
double icosec_k_1[50] = {0}, icosec_a_1[50] = {0}, icosec_b_1[50] = {0}, icosec_c_1[50] = {0};
double isec_k_1[50] = {0}, isec_a_1[50] = {0}, isec_b_1[50] = {0}, isec_c_1[50] = {0};
double icot_k_1[50] = {0}, icot_a_1[50] = {0}, icot_b_1[50] = {0}, icot_c_1[50] = {0};

double a1[50] = {0}, a2[50] = {0}, b1[50] = {0}, b2[50] = {0}; // straight line
double h[50] = {0}, k[50] = {0}, r[50] = {0};                  // circle

double red[5] = {0, 76, 205, 67, 93};
double green[5] = {0, 152, 87, 128, 73};
double blue[5] = {0, 89, 84, 188, 168};

double red_dark[5] = {255, 50, 170, 169, 198};
double green_dark[5] = {255, 162, 115, 178, 115};
double blue_dark[5] = {255, 166, 61, 86, 184};
// color
double x1_ellipse[50] = {0}, y1_ellipse[50] = {0}, major_axis[50] = {0}, minor_axis[50] = {0}; // ellipse

double R1[50] = {0}, R2[50] = {0}, constant_a2[50] = {0}; // Quad y = a (x-R1) (x-R2)

double A[50] = {0}, B[50] = {0}, C[50] = {0}; // Quad y =ax^2+bx+c

double H1[50] = {0}, K1[50] = {0}, constant_a1[50] = {0};
double H122[50] = {0}, K122[50] = {0}, constant_a122[50] = {0};    // Quad y = a(x-h)^2+k
double para2[50] = {0}, para22[50] = {0}, constant_para[50] = {0}; // Quad y = a(x-k)^2+h
double HHyper[50] = {0}, KHyper[50] = {0}, a_Hyper[50] = {0}, b_Hyper[50] = {0};
double HHyper2[50] = {0}, KHyper2[50] = {0}, a_Hyper2[50] = {0}, b_Hyper2[50] = {0};
double expo_k[50] = {0};
double expo_k2[50] = {0};
double expo_k3[50] = {0}, base3[50] = {0};
double expo_k4[50] = {0}, base4[50] = {0};

void main_menu()
{
    iSetColor(0, 0, 0);
    iShowBMP(0, 0, "background.bmp");
    iShowBMP(320, 500, "title.bmp");
    iShowBMP(470, 430, "design.bmp");
    iShowBMP(340, 360, "title_name.bmp");
    iShowBMP(740, 360, "title_ID.bmp");
    iShowBMP(400, 200, "startpkmn.bmp");
}

void drawboxInput1stwindow()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Enter the number that corresponds to what you want to plot");
    iText(5, 380 + 260, "1. Straight Lines");
    iText(5, 380 + 240, "2. Quadratic Equations");
    iText(5, 380 + 220, "3. Conics");
    iText(5, 380 + 200, "4. Exponential Functions");
    iText(5, 380 + 180, "5. Logarithmic Functions");
    iText(5, 380 + 160, "6. Trigonometric Functions");
    iText(5, 380 + 140, "7. Inverse Trigonometric Functions");
}
void SL_1st_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Enter the number that corresponds to the equation of your straight line");
    iText(0 + 5, 380 + 265, "1. y = mx + c");
    iText(0 + 5, 380 + 250, "2. x/a + y/b = 1");
    iText(0 + 5, 380 + 235, "3. y - y1 = m (x - x1)");
}
void SL_1_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(5, 380 + 280, "Please enter the value of m and c");
}
void SL_2_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(5, 380 + 280, "Please enter the values of a and b");
}
void SL_3_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(5, 380 + 280, "Please enter the values of y1, x1 and m");
}
void QUAD_1st_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Enter the number that of the type of quadratic equation you want to plot");
    iText(0 + 5, 380 + 265, "1. y = ax^2 + bx + c");
    iText(0 + 5, 380 + 250, "2. y = a(x - h)^2 + k");
    iText(0 + 5, 380 + 235, "3. y = a(x - R1)(x - R2)");
}
void QUAD_1_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Please enter the values of a, b, c");
}
void QUAD_2_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Please enter the values of a, h and k");
}
void QUAD_3_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Please enter the values of a, R1 and R2");
}
void CONICS_1st_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Enter the number that corresponds to the conic you want to draw");
    iText(0 + 5, 380 + 255, "1. Circle");
    iText(0 + 5, 380 + 230, "2. Parabola");
    iText(0 + 5, 380 + 205, "3. Ellipse");
    iText(0 + 5, 380 + 180, "4. Hyperbola");
}
void CONICS_Circle_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Enter the number that corresponds to the form you want to input parameters");
    iText(0 + 5, 380 + 265, "1. (x - h)^2 + (y - k)^2 = r^2");
    iText(0 + 5, 380 + 250, "2. x^2 + y^2 + 2gx + 2fy + c = 0");
}
void CONICS_Circle_1_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Please enter the values of h, k and r");
}
void CONICS_Circle_2_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Please enter the values of g, f and c");
}
void CONICS_Parabola_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Enter the number that corresponds to the form you want to input parameters");
    iText(0 + 5, 380 + 265, "1. y = a(x-h)^2+k");
    iText(0 + 5, 380 + 250, "2. x = a(y-k)^2 +h");
}
void CONICS_Parabola_1_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Please enter the values of a, h, k in y = a(x-h)^2+k");
}
void CONICS_Parabola_2_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Please enter the values of a, k, h in x = a(y-k)^2 +h");
}
void CONICS_Ellipse_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Please enter the values of h, k, a and b in (x-h)^2 /a^2 + (y-k)^2/ b^2 =1");
}
void CONICS_Hyperbola_1_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    iText(0 + 5, 380 + 280, "Enter the values of h, a, k and b in (x-h)^2 /a^2 - (y-k)^2/ b^2 =1");
}
void EXPONENTIAL_1st_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    // e=2.71828
    iText(0 + 5, 380 + 280, "Enter the number of the exponential equation");
    iText(0 + 5, 380 + 280 - 15, "1. y = k*e^x");
    iText(0 + 5, 380 + 280 - 30, "2. y = k*e^(-x)");
    iText(0 + 5, 380 + 280 - 45, "3. y = k*a^x");
    iText(0 + 5, 380 + 280 - 60, "4. y = k*a^(-x)");
}
void EXPONENTIAL_1_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    // e=2.71828
    iText(0 + 5, 380 + 280, "Enter the value of k");
}
void EXPONENTIAL_2_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    // e=2.71828
    iText(0 + 5, 380 + 280, "Enter the value of k");
}
void EXPONENTIAL_3_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    // e=2.71828
    iText(0 + 5, 380 + 280, "Enter the value of k and a");
}
void EXPONENTIAL_4_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    // e=2.71828
    iText(0 + 5, 380 + 280, "Enter the value of k and a");
}
void LOGARITHMIC_1st_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    // e=2.71828
    iText(0 + 5, 380 + 280, "Enter the number of the logarithmic function");
    iText(0 + 5, 380 + 280 - 15, "1. y = k + a*log(b*x + c)");
    iText(0 + 5, 380 + 280 - 30, "2. y = k + a*ln(b*x + c)");
}
void LOGARITHMIC_1_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    // e=2.71828
    iText(0 + 5, 380 + 280, "Enter the values of k, a, b, c");
}
void Trigonometric_1st_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    // e=2.71828
    iText(0 + 5, 380 + 280, "Enter the number of the trigonometric function");
    iText(0 + 5, 380 + 280 - 15, "1. y = k + a*sin(b*x+c)");
    iText(0 + 5, 380 + 280 - 30, "2. y = k + a*cos(b*x+c)");
    iText(0 + 5, 380 + 280 - 45, "3. y = k + a*tan(b*x+c)");
    iText(0 + 5, 380 + 280 - 60, "4. y = k + a*cosec(b*x+c)");
    iText(0 + 5, 380 + 280 - 75, "5. y = k + a*sec(b*x+c)");
    iText(0 + 5, 380 + 280 - 90, "6. y = k + a*cot(b*x+c)");
}
void Trigonometric_1_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    // e=2.71828
    iText(0 + 5, 380 + 280, "Enter the values of k, a, b and c");
}
void Inverse_Trigonometric_1st_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    // e=2.71828
    iText(0 + 5, 380 + 280, "Enter the number of the inverse trigonometric function");
    iText(0 + 5, 380 + 280 - 15, "1. y = k + a*arcsin(b*x+c)");
    iText(0 + 5, 380 + 280 - 30, "2. y = k + a*arccos(b*x+c)");
    iText(0 + 5, 380 + 280 - 45, "3. y = k + a*arctan(b*x+c)");
    iText(0 + 5, 380 + 280 - 60, "4. y = k + a*arccosec(b*x+c)");
    iText(0 + 5, 380 + 280 - 75, "5. y = k + a*arcsec(b*x+c)");
    iText(0 + 5, 380 + 280 - 90, "6. y = k + a*arccot(b*x+c)");
}
void Inverse_Trigonometric_1_window()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 380, 600, 300);
    iSetColor(255, 255, 255);
    // e=2.71828
    iText(0 + 5, 380 + 280, "Enter the values of k, a, b and c");
}


void drawline()
{
    for (int i = 0; i < num_lines; i++)
    {

        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        iLine(a1[i] - diff_x, b1[i] - diff_y, a2[i] - diff_x, b2[i] - diff_y);
        iLine(a1[i] - diff_x + 1, b1[i] - diff_y, a2[i] - diff_x + 1, b2[i] - diff_y);
        iLine(a1[i] - diff_x + 2, b1[i] - diff_y, a2[i] - diff_x + 2, b2[i] - diff_y);
    }
}
void drawcircle()
{

    for (int i = 0; i < num_circles; i++)
    {
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        iCircle(h[i] - diff_x, k[i] - diff_y, r[i], 500);
        iCircle(h[i] - diff_x, k[i] - diff_y, r[i] + 0.5, 500);
        iCircle(h[i] - diff_x, k[i] - diff_y, r[i] + 1, 500);
    }
}
void Ellipse()
{

    for (int i = 0; i < num_ellipses; i++)
    {
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        iEllipse(x1_ellipse[i] - diff_x, y1_ellipse[i] - diff_y, major_axis[i], minor_axis[i], 500);
        iEllipse(x1_ellipse[i] - diff_x, y1_ellipse[i] - diff_y, major_axis[i] + 0.5, minor_axis[i] + 0.5, 500);
        iEllipse(x1_ellipse[i] - diff_x, y1_ellipse[i] - diff_y, major_axis[i] - 0.5, minor_axis[i] - 0.5, 500);
    }
}
// quadratic-1
void drawCurvePositive()
{
    double xPrev121, yPrev121, x121, y121;

    for (int i = 0; i < num_quad_curves; i++)
    {

        xPrev121 = -B[i] / (2 * A[i]);
        yPrev121 = A[i] * xPrev121 * xPrev121 + B[i] * xPrev121 + C[i];
        x121 = xPrev121 + 0.15;
        y121 = (A[i] * x121 * x121 + B[i] * x121 + C[i]);

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev121 * 30 + Ox - diff_x, yPrev121 * 30 - diff_y + Oy, x121 * 30 + Ox - diff_x, y121 * 30 + Oy - diff_y);
            iLine(xPrev121 * 30 + Ox + 0.75 - diff_x, yPrev121 * 30 - diff_y + Oy, x121 * 30 + 0.75 + Ox - diff_x, y121 * 30 + Oy - diff_y);
            iLine(xPrev121 * 30 + Ox + 0.25 - diff_x, yPrev121 * 30 - diff_y + Oy, x121 * 30 + 0.25 + Ox - diff_x, y121 * 30 + Oy - diff_y);
            iLine(xPrev121 * 30 + Ox + 0.5 - diff_x, yPrev121 * 30 - diff_y + Oy, x121 * 30 + 0.5 + Ox - diff_x, y121 * 30 + Oy - diff_y);

            xPrev121 = x121;
            yPrev121 = y121;
            x121 += 0.15;
            y121 = A[i] * x121 * x121 + B[i] * x121 + C[i];
        }
    }
}
void drawCurveNegative()
{
    double xPrev121, yPrev121, x121, y121;
    for (int i = 0; i < num_quad_curves; i++)
    {
        xPrev121 = -B[i] / (2 * A[i]);
        yPrev121 = A[i] * xPrev121 * xPrev121 + B[i] * xPrev121 + C[i];
        x121 = xPrev121 - 0.15;
        y121 = (A[i] * x121 * x121 + B[i] * x121 + C[i]);

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev121 * 30 + Ox - diff_x, yPrev121 * 30 - diff_y + Oy, x121 * 30 + Ox - diff_x, y121 * 30 + Oy - diff_y);
            iLine(xPrev121 * 30 + Ox + 0.75 - diff_x, yPrev121 * 30 - diff_y + Oy, x121 * 30 + 0.75 + Ox - diff_x, y121 * 30 + Oy - diff_y);
            iLine(xPrev121 * 30 + Ox + 0.25 - diff_x, yPrev121 * 30 - diff_y + Oy, x121 * 30 + 0.25 + Ox - diff_x, y121 * 30 + Oy - diff_y);
            iLine(xPrev121 * 30 + Ox + 0.5 - diff_x, yPrev121 * 30 - diff_y + Oy, x121 * 30 + 0.5 + Ox - diff_x, y121 * 30 + Oy - diff_y);

            xPrev121 = x121;
            yPrev121 = y121;
            x121 -= 0.15;
            y121 = A[i] * x121 * x121 + B[i] * x121 + C[i];
        }
    }
}
// qaudratic-2
void draw_QuadCurve_Positive()
{
    double xPrev122, yPrev122, x122, y122;

    for (int i = 0; i < num_quad_curves; i++)
    {

        xPrev122 = H122[i];
        yPrev122 = K122[i];
        x122 = xPrev122;
        y122 = yPrev122;

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev122 * 30 + Ox - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.75 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.75 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.25 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.25 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.5 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.5 + Ox - diff_x, y122 * 30 + Oy - diff_y);

            xPrev122 = x122;
            yPrev122 = y122;
            x122 += 0.15;
            y122 = constant_a122[i] * (x122 - H122[i]) * (x122 - H122[i]) + K122[i];
        }
    }
}
void draw_QuadCurve_Negative()
{
    double xPrev122, yPrev122, x122, y122;

    for (int i = 0; i < num_quad_curves; i++)
    {

        xPrev122 = H122[i];
        yPrev122 = K122[i];
        x122 = xPrev122 + 0.1;
        y122 = yPrev122 + 0.1;

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev122 * 30 + Ox - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.75 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.75 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.25 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.25 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.5 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.5 + Ox - diff_x, y122 * 30 + Oy - diff_y);

            xPrev122 = x122;
            yPrev122 = y122;
            x122 -= 0.15;
            y122 = constant_a122[i] * (x122 - H122[i]) * (x122 - H122[i]) + K122[i];
        }
    }
}
// quadratic-3
void draw__Curve__Positive()
{
    double xPrev123, yPrev123, x123, y123;

    for (int i = 0; i < num_quad_curves; i++)
    {

        if (R2[i] == R1[i])
        {
            xPrev123 = R1[i];
            yPrev123 = constant_a2[i] * (xPrev123 - R1[i]) * (xPrev123 - R2[i]);
        }

        else
        {
            xPrev123 = (R1[i] + R2[i]) / 2.0;
            yPrev123 = constant_a2[i] * (xPrev123 - R1[i]) * (xPrev123 - R2[i]);
        }

        x123 = xPrev123 + 0.1;
        y123 = constant_a2[i] * (x123 - R1[i]) * (x123 - R2[i]);

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev123 * 30 + Ox - diff_x, yPrev123 * 30 - diff_y + Oy, x123 * 30 + Ox - diff_x, y123 * 30 + Oy - diff_y);
            iLine(xPrev123 * 30 + Ox + 0.75 - diff_x, yPrev123 * 30 - diff_y + Oy, x123 * 30 + 0.75 + Ox - diff_x, y123 * 30 + Oy - diff_y);
            iLine(xPrev123 * 30 + Ox + 0.25 - diff_x, yPrev123 * 30 - diff_y + Oy, x123 * 30 + 0.25 + Ox - diff_x, y123 * 30 + Oy - diff_y);
            iLine(xPrev123 * 30 + Ox + 0.5 - diff_x, yPrev123 * 30 - diff_y + Oy, x123 * 30 + 0.5 + Ox - diff_x, y123 * 30 + Oy - diff_y);

            xPrev123 = x123;
            yPrev123 = y123;
            x123 += 0.15;
            y123 = constant_a2[i] * (x123 - R1[i]) * (x123 - R2[i]);
        }
    }
}
void draw__Curve__Negative()
{
    double xPrev123, yPrev123, x123, y123;

    for (int i = 0; i < num_quad_curves; i++)
    {

        if (R2[i] == R1[i])
        {
            xPrev123 = R1[i];
            yPrev123 = constant_a2[i] * (xPrev123 - R1[i]) * (xPrev123 - R2[i]);
        }

        else
        {
            xPrev123 = (R1[i] + R2[i]) / 2.0;
            yPrev123 = constant_a2[i] * (xPrev123 - R1[i]) * (xPrev123 - R2[i]);
        }

        // x123 = xPrev123 + 0.1;
        x123 = xPrev123 - 0.1;
        y123 = constant_a2[i] * (x123 - R1[i]) * (x123 - R2[i]);

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev123 * 30 + Ox - diff_x, yPrev123 * 30 - diff_y + Oy, x123 * 30 + Ox - diff_x, y123 * 30 + Oy - diff_y);
            iLine(xPrev123 * 30 + Ox + 0.75 - diff_x, yPrev123 * 30 - diff_y + Oy, x123 * 30 + 0.75 + Ox - diff_x, y123 * 30 + Oy - diff_y);
            iLine(xPrev123 * 30 + Ox + 0.25 - diff_x, yPrev123 * 30 - diff_y + Oy, x123 * 30 + 0.25 + Ox - diff_x, y123 * 30 + Oy - diff_y);
            iLine(xPrev123 * 30 + Ox + 0.5 - diff_x, yPrev123 * 30 - diff_y + Oy, x123 * 30 + 0.5 + Ox - diff_x, y123 * 30 + Oy - diff_y);

            xPrev123 = x123;
            yPrev123 = y123;
            x123 -= 0.15;
            y123 = constant_a2[i] * (x123 - R1[i]) * (x123 - R2[i]);
        }
    }
}

// parabola
void draw_Curve_Positive()
{
    double xPrev122, yPrev122, x122, y122;

    for (int i = 0; i < num_parabolas; i++)
    {

        xPrev122 = H1[i];
        yPrev122 = K1[i];
        x122 = xPrev122;
        y122 = yPrev122;

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev122 * 30 + Ox - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.75 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.75 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.25 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.25 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.5 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.5 + Ox - diff_x, y122 * 30 + Oy - diff_y);

            xPrev122 = x122;
            yPrev122 = y122;
            x122 += 0.15;
            y122 = constant_a1[i] * (x122 - H1[i]) * (x122 - H1[i]) + K1[i];
        }
    }
}
void draw_Curve_Negative()
{
    double xPrev122, yPrev122, x122, y122;

    for (int i = 0; i < num_parabolas; i++)
    {

        xPrev122 = H1[i];
        yPrev122 = K1[i];
        x122 = xPrev122 + 0.1;
        y122 = yPrev122 + 0.1;

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev122 * 30 + Ox - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.75 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.75 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.25 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.25 + Ox - diff_x, y122 * 30 + Oy - diff_y);
            iLine(xPrev122 * 30 + Ox + 0.5 - diff_x, yPrev122 * 30 - diff_y + Oy, x122 * 30 + 0.5 + Ox - diff_x, y122 * 30 + Oy - diff_y);

            xPrev122 = x122;
            yPrev122 = y122;
            x122 -= 0.15;
            y122 = constant_a1[i] * (x122 - H1[i]) * (x122 - H1[i]) + K1[i];
        }
    }
}

// parabola-2
void draw_Curve_Horizontal_Parabola_Positive()
{
    double xPrev1322, yPrev1322, x1322, y1322;

    for (int i = 0; i < num_parabolas; i++)
    {

        xPrev1322 = para2[i];
        yPrev1322 = para22[i];

        x1322 = xPrev1322;
        y1322 = yPrev1322;

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev1322 * 30 + Ox - diff_x, yPrev1322 * 30 - diff_y + Oy, x1322 * 30 + Ox - diff_x, y1322 * 30 + Oy - diff_y);
            iLine(xPrev1322 * 30 + Ox + 0.75 - diff_x, yPrev1322 * 30 - diff_y + Oy, x1322 * 30 + 0.75 + Ox - diff_x, y1322 * 30 + Oy - diff_y);
            iLine(xPrev1322 * 30 + Ox + 0.25 - diff_x, yPrev1322 * 30 - diff_y + Oy, x1322 * 30 + 0.25 + Ox - diff_x, y1322 * 30 + Oy - diff_y);
            iLine(xPrev1322 * 30 + Ox + 0.5 - diff_x, yPrev1322 * 30 - diff_y + Oy, x1322 * 30 + 0.5 + Ox - diff_x, y1322 * 30 + Oy - diff_y);

            xPrev1322 = x1322;
            yPrev1322 = y1322;
            y1322 += 0.15;
            x1322 = constant_para[i] * (y1322 - para22[i]) * (y1322 - para22[i]) + para2[i];
        }
    }
}
void draw_Curve_Horizontal_Parabola_Negative()
{
    double xPrev1322, yPrev1322, x1322, y1322;

    for (int i = 0; i < num_parabolas; i++)
    {

        xPrev1322 = para2[i];
        yPrev1322 = para22[i];
        x1322 = xPrev1322;
        y1322 = yPrev1322;

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev1322 * 30 + Ox - diff_x, yPrev1322 * 30 - diff_y + Oy, x1322 * 30 + Ox - diff_x, y1322 * 30 + Oy - diff_y);
            iLine(xPrev1322 * 30 + Ox + 0.75 - diff_x, yPrev1322 * 30 - diff_y + Oy, x1322 * 30 + 0.75 + Ox - diff_x, y1322 * 30 + Oy - diff_y);
            iLine(xPrev1322 * 30 + Ox + 0.25 - diff_x, yPrev1322 * 30 - diff_y + Oy, x1322 * 30 + 0.25 + Ox - diff_x, y1322 * 30 + Oy - diff_y);
            iLine(xPrev1322 * 30 + Ox + 0.5 - diff_x, yPrev1322 * 30 - diff_y + Oy, x1322 * 30 + 0.5 + Ox - diff_x, y1322 * 30 + Oy - diff_y);

            xPrev1322 = x1322;
            yPrev1322 = y1322;
            y1322 -= 0.15;
            x1322 = constant_para[i] * (y1322 - para22[i]) * (y1322 - para22[i]) + para2[i];
        }
    }
}

// hyperbola
void drawHyperbolaUpper()
{
    double xPrev134, yPrev134, x134, y134;

    for (int i = 0; i < num_hyperbolas; i++)
    {

        xPrev134 = a_Hyper[i] + HHyper[i];
        yPrev134 = KHyper[i];

        x134 = xPrev134;

        y134 = yPrev134;

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);

            iLine(xPrev134 * 30 + Ox - diff_x, yPrev134 * 30 - diff_y + Oy, x134 * 30 + Ox - diff_x, y134 * 30 + Oy - diff_y);
            iLine(xPrev134 * 30 + Ox + 1 - diff_x, yPrev134 * 30 - diff_y + Oy, x134 * 30 + Ox + 1 - diff_x, y134 * 30 + Oy - diff_y);
            iLine(xPrev134 * 30 + Ox - 1 - diff_x, yPrev134 * 30 - diff_y + Oy, x134 * 30 + Ox - 1 - diff_x, y134 * 30 + Oy - diff_y);

            iLine((-xPrev134 + a_Hyper[i] + HHyper[i]) * 30 + Ox - diff_x, yPrev134 * 30 - diff_y + Oy, (-x134 + a_Hyper[i] + HHyper[i]) * 30 + Ox - diff_x, y134 * 30 + Oy - diff_y);
            iLine((-xPrev134 + a_Hyper[i] + HHyper[i]) * 30 + 1 + Ox - diff_x, yPrev134 * 30 - diff_y + Oy, (-x134 + a_Hyper[i] + HHyper[i]) * 30 + Ox + 1 - diff_x, y134 * 30 + Oy - diff_y);
            iLine((-xPrev134 + a_Hyper[i] + HHyper[i]) * 30 + Ox - 1 - diff_x, yPrev134 * 30 - diff_y + Oy, (-x134 + a_Hyper[i] + HHyper[i]) * 30 + Ox - 1 - diff_x, y134 * 30 + Oy - diff_y);

            xPrev134 = x134;
            yPrev134 = y134;
            x134 += 0.15;
            y134 = KHyper[i] + (b_Hyper[i] / a_Hyper[i]) * sqrt((xPrev134 - HHyper[i]) * (xPrev134 - HHyper[i]) - a_Hyper[i] * a_Hyper[i]);
        }
    }
}
void drawHyperbolaLower()
{
    double xPrev134, yPrev134, x134, y134;

    for (int i = 0; i < num_hyperbolas; i++)
    {

        xPrev134 = a_Hyper[i] + HHyper[i];
        yPrev134 = KHyper[i];

        x134 = xPrev134;
        y134 = yPrev134;

        for (double j = 0; j <= 100; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev134 * 30 + Ox - diff_x, yPrev134 * 30 - diff_y + Oy, x134 * 30 + Ox - diff_x, y134 * 30 + Oy - diff_y);
            iLine(xPrev134 * 30 + 1 + Ox - diff_x, yPrev134 * 30 - diff_y + Oy, x134 * 30 + 1 + Ox - diff_x, y134 * 30 + Oy - diff_y);
            iLine(xPrev134 * 30 - 1 + Ox - diff_x, yPrev134 * 30 - diff_y + Oy, x134 * 30 - 1 + Ox - diff_x, y134 * 30 + Oy - diff_y);

            iLine((-xPrev134 + a_Hyper[i] + HHyper[i]) * 30 + Ox - diff_x, yPrev134 * 30 - diff_y + Oy, (-x134 + a_Hyper[i] + HHyper[i]) * 30 + Ox - diff_x, y134 * 30 + Oy - diff_y);
            iLine((-xPrev134 + a_Hyper[i] + HHyper[i]) * 30 + 1 + Ox - diff_x, yPrev134 * 30 - diff_y + Oy, (-x134 + a_Hyper[i] + HHyper[i]) * 30 + Ox + 1 - diff_x, y134 * 30 + Oy - diff_y);
            iLine((-xPrev134 + a_Hyper[i] + HHyper[i]) * 30 + Ox - 1 - diff_x, yPrev134 * 30 - diff_y + Oy, (-x134 + a_Hyper[i] + HHyper[i]) * 30 + Ox - 1 - diff_x, y134 * 30 + Oy - diff_y);

            xPrev134 = x134;
            yPrev134 = y134;

            x134 += 0.15;
            y134 = KHyper[i] - (b_Hyper[i] / a_Hyper[i]) * sqrt((xPrev134 - HHyper[i]) * (xPrev134 - HHyper[i]) - a_Hyper[i] * a_Hyper[i]);
        }
    }
}
// exponential
void draw_exponentialcurve1()
{
    double xPrev141, yPrev141, x141, y141;

    for (int i = 0; i < num_expo_curves_1; i++)
    {

        xPrev141 = -100;
        yPrev141 = expo_k[i] * pow(2.71828, xPrev141);
        x141 = xPrev141 + 0.15;
        y141 = expo_k[i] * pow(2.71828, x141);
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 800; j++)
        {

            iLine(xPrev141 * 30 + Ox - diff_x, yPrev141 * 30 - diff_y + Oy, x141 * 30 + Ox - diff_x, y141 * 30 + Oy - diff_y);
            iLine(xPrev141 * 30 + Ox - diff_x + 0.5, yPrev141 * 30 - diff_y + Oy, x141 * 30 + Ox - diff_x + 0.5, y141 * 30 + Oy - diff_y);
            iLine(xPrev141 * 30 + Ox - diff_x - 0.5, yPrev141 * 30 - diff_y + Oy, x141 * 30 + Ox - diff_x - 0.5, y141 * 30 + Oy - diff_y);

            xPrev141 = x141;
            yPrev141 = y141;
            x141 += 0.15;
            y141 = expo_k[i] * pow(2.71828, x141);
        }
    }
}
void draw_exponentialcurve2()
{
    double xPrev142, yPrev142, x142, y142;

    for (int i = 0; i < num_expo_curves_2; i++)
    {

        xPrev142 = 100;
        yPrev142 = expo_k2[i] * pow(2.71828, -xPrev142);
        x142 = xPrev142 - 0.15;
        y142 = expo_k2[i] * pow(2.71828, -x142);

        for (int j = 0; j <= 800; j++)
        {

            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);

            iLine(xPrev142 * 30 + Ox - diff_x, yPrev142 * 30 - diff_y + Oy, x142 * 30 + Ox - diff_x, y142 * 30 + Oy - diff_y);
            iLine(xPrev142 * 30 + Ox - diff_x + 0.5, yPrev142 * 30 - diff_y + Oy, x142 * 30 + Ox - diff_x + 0.5, y142 * 30 + Oy - diff_y);
            iLine(xPrev142 * 30 + Ox - diff_x - 0.5, yPrev142 * 30 - diff_y + Oy, x142 * 30 + Ox - diff_x - 0.5, y142 * 30 + Oy - diff_y);

            xPrev142 = x142;
            yPrev142 = y142;
            x142 -= 0.15;
            y142 = expo_k2[i] * pow(2.71828, -x142);
        }
    }
}
void draw_exponentialcurve3()
{
    double xPrev143, yPrev143, x143, y143;

    for (int i = 0; i < num_expo_curves_3; i++)
    {

        xPrev143 = -120;
        yPrev143 = expo_k3[i] * pow(base3[i], xPrev143);
        x143 = xPrev143;
        y143 = yPrev143;

        for (double j = 0; j <= 150; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev143 * 30 + Ox - diff_x, yPrev143 * 30 - diff_y + Oy, x143 * 30 + Ox - diff_x, y143 * 30 + Oy - diff_y);
            iLine(xPrev143 * 30 + Ox - 0.5 - diff_x, yPrev143 * 30 - diff_y + Oy, x143 * 30 - 0.5 + Ox - diff_x, y143 * 30 + Oy - diff_y);
            iLine(xPrev143 * 30 + Ox + 0.5 - diff_x, yPrev143 * 30 - diff_y + Oy, x143 * 30 + 0.5 + Ox - diff_x, y143 * 30 + Oy - diff_y);

            xPrev143 = x143;
            yPrev143 = y143;
            x143 += 0.15;
            y143 = expo_k3[i] * pow(base3[i], x143);
        }
    }
}
void draw_exponentialcurve4()
{
    double xPrev144, yPrev144, x144, y144;

    for (int i = 0; i < num_expo_curves_4; i++)
    {

        xPrev144 = 120;
        yPrev144 = expo_k4[i] * pow(base4[i], -xPrev144);
        x144 = xPrev144;
        y144 = yPrev144;

        for (double j = 0; j <= 150; j += 0.15)
        {
            int temp = i % 5;
            if (darkmode)
                iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
            else
                iSetColor(red[temp], green[temp], blue[temp]);
            iLine(xPrev144 * 30 + Ox - diff_x, yPrev144 * 30 - diff_y + Oy, x144 * 30 + Ox - diff_x, y144 * 30 + Oy - diff_y);
            iLine(xPrev144 * 30 + Ox - 0.5 - diff_x, yPrev144 * 30 - diff_y + Oy, x144 * 30 - 0.5 + Ox - diff_x, y144 * 30 + Oy - diff_y);
            iLine(xPrev144 * 30 + Ox + 0.5 - diff_x, yPrev144 * 30 - diff_y + Oy, x144 * 30 + 0.5 + Ox - diff_x, y144 * 30 + Oy - diff_y);

            xPrev144 = x144;
            yPrev144 = y144;
            x144 -= 0.15;
            y144 = expo_k4[i] * pow(base4[i], -x144);
        }
    }
}
//Logarithmic
void draw_logarithmic_151()

{
    double xPrev151, yPrev151, x151, y151;

    for (int i = 0; i < num_log1; i++)
    {

        xPrev151 = -10;
        yPrev151 = log_k_1[i] + log_a_1[i] * log10(log_b_1[i] * xPrev151 + log_c_1[i]);
        x151 = xPrev151;
        y151 = log_k_1[i] + log_a_1[i] * log10(log_b_1[i] * x151 + log_c_1[i]);
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 800; j++)
        {

            iLine(xPrev151 * 30 + Ox - diff_x, yPrev151 * 30 - diff_y + Oy, x151 * 30 + Ox - diff_x, y151 * 30 + Oy - diff_y);
            iLine(xPrev151 * 30 + Ox - diff_x + 0.5, yPrev151 * 30 + .5 - diff_y + Oy, x151 * 30 + Ox - diff_x + 0.5, y151 * 30 + Oy + .5 - diff_y);
            iLine(xPrev151 * 30 + Ox - diff_x - 0.5, yPrev151 * 30 - .5 - diff_y + Oy, x151 * 30 + Ox - diff_x - 0.5, y151 * 30 - .5 + Oy - diff_y);

            xPrev151 = x151;
            yPrev151 = y151;
            x151 += 0.15;
            y151 = log_k_1[i] + log_a_1[i] * log10(log_b_1[i] * x151 + log_c_1[i]);
        }
    }
}
void draw_logarithmic_152()

{
    double xPrev152, yPrev152, x152, y152;

    for (int i = 0; i < num_log2; i++)
    {

        xPrev152 = -10;
        yPrev152 = log_kk[i] + log_aa[i] * log(log_bb[i] * xPrev152 + log_cc[i]);

        x152 = xPrev152;
        y152 = log_kk[i] + log_aa[i] * log(log_bb[i] * x152 + log_cc[i]);
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);

        for (int j = 0; j <= 800; j++)
        {

            iLine(xPrev152 * 30 + Ox - diff_x, yPrev152 * 30 - diff_y + Oy, x152 * 30 + Ox - diff_x, y152 * 30 + Oy - diff_y);
            iLine(xPrev152 * 30 + Ox - diff_x + 0.5, yPrev152 * 30 + .5 - diff_y + Oy, x152 * 30 + Ox - diff_x + 0.5, y152 * 30 + Oy + .5 - diff_y);
            iLine(xPrev152 * 30 + Ox - diff_x - 0.5, yPrev152 * 30 - .5 - diff_y + Oy, x152 * 30 + Ox - diff_x - 0.5, y152 * 30 - .5 + Oy - diff_y);

            xPrev152 = x152;
            yPrev152 = y152;
            x152 += 0.15;
            y152 = log_kk[i] + log_aa[i] * log(log_bb[i] * x152 + log_cc[i]);
        }
    }
}
//Trigonometric
void draw_sin()
{

    double xPrev161, yPrev161, x161, y161;

    for (int i = 0; i < num_trig_sin; i++)
    {

        xPrev161 = -100;
        yPrev161 = sin_k_1[i] + sin_a_1[i] * sin(sin_b_1[i] * xPrev161 + sin_c_1[i]);

        x161 = xPrev161;
        y161 = sin_k_1[i] + sin_a_1[i] * sin(sin_b_1[i] * x161 + sin_c_1[i]);
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {

            iLine(xPrev161 * 30 + Ox - diff_x, yPrev161 * 30 - diff_y + Oy, x161 * 30 + Ox - diff_x, y161 * 30 + Oy - diff_y);
            iLine(xPrev161 * 30 + Ox - diff_x + 0.5, yPrev161 * 30 + .5 - diff_y + Oy, x161 * 30 + Ox - diff_x + 0.5, y161 * 30 + Oy + .5 - diff_y);
            iLine(xPrev161 * 30 + Ox - diff_x - 0.5, yPrev161 * 30 - .5 - diff_y + Oy, x161 * 30 + Ox - diff_x - 0.5, y161 * 30 - .5 + Oy - diff_y);

            xPrev161 = x161;
            yPrev161 = y161;
            x161 += 0.15;
            y161 = sin_k_1[i] + sin_a_1[i] * sin(sin_b_1[i] * x161 + sin_c_1[i]);
        }
    }
}
void draw_cos()
{

    double xPrev162, yPrev162, x162, y162;

    for (int i = 0; i < num_trig_cos; i++)
    {

        xPrev162 = -100;
        yPrev162 = cos_k_1[i] + cos_a_1[i] * cos(cos_b_1[i] * xPrev162 + cos_c_1[i]);

        x162 = xPrev162;
        y162 = cos_k_1[i] + cos_a_1[i] * cos(cos_b_1[i] * x162 + cos_c_1[i]);
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {

            iLine(xPrev162 * 30 + Ox - diff_x, yPrev162 * 30 - diff_y + Oy, x162 * 30 + Ox - diff_x, y162 * 30 + Oy - diff_y);
            iLine(xPrev162 * 30 + Ox - diff_x + 0.5, yPrev162 * 30 + .5 - diff_y + Oy, x162 * 30 + Ox - diff_x + 0.5, y162 * 30 + Oy + .5 - diff_y);
            iLine(xPrev162 * 30 + Ox - diff_x - 0.5, yPrev162 * 30 - .5 - diff_y + Oy, x162 * 30 + Ox - diff_x - 0.5, y162 * 30 - .5 + Oy - diff_y);

            xPrev162 = x162;
            yPrev162 = y162;
            x162 += 0.15;
            y162 = cos_k_1[i] + cos_a_1[i] * cos(cos_b_1[i] * x162 + cos_c_1[i]);
        }
    }
}
void draw_tan()
{

    double xPrev163, yPrev163, x163, y163;

    for (int i = 0; i < num_trig_tan; i++)
    {

        xPrev163 = -100;
        yPrev163 = tan_k_1[i] + tan_a_1[i] * tan(tan_b_1[i] * xPrev163 + tan_c_1[i]);

        x163 = xPrev163;
        y163 = tan_k_1[i] + tan_a_1[i] * tan(tan_b_1[i] * x163 + tan_c_1[i]);
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {
            if (yPrev163 < y163)
            {
                iLine(xPrev163 * 30 + Ox - diff_x, yPrev163 * 30 - diff_y + Oy, x163 * 30 + Ox - diff_x, y163 * 30 + Oy - diff_y);
                iLine(xPrev163 * 30 + Ox - diff_x + 0.5, yPrev163 * 30 + .5 - diff_y + Oy, x163 * 30 + Ox - diff_x + 0.5, y163 * 30 + Oy + .5 - diff_y);
                iLine(xPrev163 * 30 + Ox - diff_x - 0.5, yPrev163 * 30 - .5 - diff_y + Oy, x163 * 30 + Ox - diff_x - 0.5, y163 * 30 - .5 + Oy - diff_y);
            }

            xPrev163 = x163;
            yPrev163 = y163;
            x163 += 0.15;
            y163 = tan_k_1[i] + tan_a_1[i] * tan(tan_b_1[i] * xPrev163 + tan_c_1[i]);
        }
    }
}
void draw_cosec_half()
{

    double xPrev164, yPrev164, x164, y164;

    for (int i = 0; i < num_trig_cosec; i++)
    {

        xPrev164 = -100;
        yPrev164 = cosec_k_1[i] + cosec_a_1[i] * sin(cosec_b_1[i] * xPrev164 + cosec_c_1[i]);

        x164 = xPrev164;
        y164 = cosec_k_1[i] + cosec_a_1[i] * 1 / (sin(cosec_b_1[i] * x164 + cosec_c_1[i]));
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {
            if (yPrev164 < y164 && y164 - yPrev164 < 26)
            {
                iLine(xPrev164 * 30 + Ox - diff_x, yPrev164 * 30 - diff_y + Oy, x164 * 30 + Ox - diff_x, y164 * 30 + Oy - diff_y);
                iLine(xPrev164 * 30 + Ox - diff_x + 0.5, yPrev164 * 30 + .5 - diff_y + Oy, x164 * 30 + Ox - diff_x + 0.5, y164 * 30 + Oy + .5 - diff_y);
                iLine(xPrev164 * 30 + Ox - diff_x - 0.5, yPrev164 * 30 - .5 - diff_y + Oy, x164 * 30 + Ox - diff_x - 0.5, y164 * 30 - .5 + Oy - diff_y);
            }

            xPrev164 = x164;
            yPrev164 = y164;
            x164 += 0.15;
            y164 = cosec_k_1[i] + cosec_a_1[i] * 1 / (sin(cosec_b_1[i] * x164 + cosec_c_1[i]));
        }
    }
}
void draw_cosec_otherhalf()
{

    double xPrev164, yPrev164, x164, y164;

    for (int i = 0; i < num_trig_cosec; i++)
    {

        xPrev164 = -100;
        yPrev164 = cosec_k_1[i] + cosec_a_1[i] * sin(cosec_b_1[i] * xPrev164 + cosec_c_1[i]);

        x164 = xPrev164;
        y164 = cosec_k_1[i] + cosec_a_1[i] * 1 / (sin(cosec_b_1[i] * x164 + cosec_c_1[i]));
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {
            if (yPrev164 > y164 && yPrev164 - y164 < 26)
            {
                iLine(xPrev164 * 30 + Ox - diff_x, yPrev164 * 30 - diff_y + Oy, x164 * 30 + Ox - diff_x, y164 * 30 + Oy - diff_y);
                iLine(xPrev164 * 30 + Ox - diff_x + 0.5, yPrev164 * 30 + .5 - diff_y + Oy, x164 * 30 + Ox - diff_x + 0.5, y164 * 30 + Oy + .5 - diff_y);
                iLine(xPrev164 * 30 + Ox - diff_x - 0.5, yPrev164 * 30 - .5 - diff_y + Oy, x164 * 30 + Ox - diff_x - 0.5, y164 * 30 - .5 + Oy - diff_y);
            }

            xPrev164 = x164;
            yPrev164 = y164;
            x164 += 0.15;
            y164 = cosec_k_1[i] + cosec_a_1[i] * 1 / (sin(cosec_b_1[i] * x164 + cosec_c_1[i]));
        }
    }
}
void draw_sec_half()
{

    double xPrev165, yPrev165, x165, y165;

    for (int i = 0; i < num_trig_sec; i++)
    {

        xPrev165 = -100;
        yPrev165 = sec_k_1[i] + sec_a_1[i] * 1 / cos(sec_b_1[i] * xPrev165 + sec_c_1[i]);

        x165 = xPrev165;
        y165 = sec_k_1[i] + sec_a_1[i] * 1 / (cos(sec_b_1[i] * x165 + sec_c_1[i]));
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {

            if (yPrev165 < y165 && y165 - yPrev165 < 26)
            {
                iLine(xPrev165 * 30 + Ox - diff_x, yPrev165 * 30 - diff_y + Oy, x165 * 30 + Ox - diff_x, y165 * 30 + Oy - diff_y);
                iLine(xPrev165 * 30 + Ox - diff_x + 0.5, yPrev165 * 30 + .5 - diff_y + Oy, x165 * 30 + Ox - diff_x + 0.5, y165 * 30 + Oy + .5 - diff_y);
                iLine(xPrev165 * 30 + Ox - diff_x - 0.5, yPrev165 * 30 - .5 - diff_y + Oy, x165 * 30 + Ox - diff_x - 0.5, y165 * 30 - .5 + Oy - diff_y);
            }

            xPrev165 = x165;
            yPrev165 = y165;
            x165 += 0.15;
            y165 = sec_k_1[i] + sec_a_1[i] * 1 / (cos(sec_b_1[i] * x165 + sec_c_1[i]));
        }
    }
}
void draw_sec_otherhalf()
{

    double xPrev165, yPrev165, x165, y165;

    for (int i = 0; i < num_trig_sec; i++)
    {

        xPrev165 = -100;
        yPrev165 = sec_k_1[i] + sec_a_1[i] * 1 / cos(sec_b_1[i] * xPrev165 + sec_c_1[i]);

        x165 = xPrev165;
        y165 = sec_k_1[i] + sec_a_1[i] * 1 / (cos(sec_b_1[i] * x165 + sec_c_1[i]));
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {
            if (yPrev165 > y165 && yPrev165 - y165 < 26)
            {
                iLine(xPrev165 * 30 + Ox - diff_x, yPrev165 * 30 - diff_y + Oy, x165 * 30 + Ox - diff_x, y165 * 30 + Oy - diff_y);
                iLine(xPrev165 * 30 + Ox - diff_x + 0.5, yPrev165 * 30 + .5 - diff_y + Oy, x165 * 30 + Ox - diff_x + 0.5, y165 * 30 + Oy + .5 - diff_y);
                iLine(xPrev165 * 30 + Ox - diff_x - 0.5, yPrev165 * 30 - .5 - diff_y + Oy, x165 * 30 + Ox - diff_x - 0.5, y165 * 30 - .5 + Oy - diff_y);
            }

            xPrev165 = x165;
            yPrev165 = y165;
            x165 += 0.15;
            y165 = sec_k_1[i] + sec_a_1[i] * 1 / (cos(sec_b_1[i] * x165 + sec_c_1[i]));
        }
    }
}
void draw_cot()
{

    double xPrev166, yPrev166, x166, y166;

    for (int i = 0; i < num_trig_cot; i++)
    {

        xPrev166 = -100;
        yPrev166 = cot_k_1[i] + cot_a_1[i] * 1 / (tan(cot_b_1[i] * xPrev166 + cot_c_1[i]));

        x166 = xPrev166;
        y166 = cot_k_1[i] + cot_a_1[i] * 1 / (tan(cot_b_1[i] * x166 + cot_c_1[i]));
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {
            if (yPrev166 > y166)
            {
                iLine(xPrev166 * 30 + Ox - diff_x, yPrev166 * 30 - diff_y + Oy, x166 * 30 + Ox - diff_x, y166 * 30 + Oy - diff_y);
                iLine(xPrev166 * 30 + Ox - diff_x + 0.5, yPrev166 * 30 + .5 - diff_y + Oy, x166 * 30 + Ox - diff_x + 0.5, y166 * 30 + Oy + .5 - diff_y);
                iLine(xPrev166 * 30 + Ox - diff_x - 0.5, yPrev166 * 30 - .5 - diff_y + Oy, x166 * 30 + Ox - diff_x - 0.5, y166 * 30 - .5 + Oy - diff_y);
            }

            xPrev166 = x166;
            yPrev166 = y166;
            x166 += 0.15;
            y166 = cot_k_1[i] + cot_a_1[i] * 1 / (tan(cot_b_1[i] * x166 + cot_c_1[i]));
        }
    }
}
//Inverse Trigonometric
void draw_sin_inv()
{

    double xPrev171, yPrev171, x171, y171;

    for (int i = 0; i < inum_trig_sin; i++)
    {

        xPrev171 = -100;
        yPrev171 = isin_k_1[i] + isin_a_1[i] * asin(isin_b_1[i] * xPrev171 + isin_c_1[i]);

        x171 = xPrev171;
        y171 = isin_k_1[i] + isin_a_1[i] * asin(isin_b_1[i] * x171 + isin_c_1[i]);
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {

            iLine(xPrev171 * 30 + Ox - diff_x, yPrev171 * 30 - diff_y + Oy, x171 * 30 + Ox - diff_x, y171 * 30 + Oy - diff_y);
            iLine(xPrev171 * 30 + Ox - diff_x + 1, yPrev171 * 30 + .5 - diff_y + Oy, x171 * 30 + Ox - diff_x + 0.5, y171 * 30 + Oy + 1 - diff_y);
            iLine(xPrev171 * 30 + Ox - diff_x - 1, yPrev171 * 30 - .5 - diff_y + Oy, x171 * 30 + Ox - diff_x - 0.5, y171 * 30 - 1 + Oy - diff_y);

            xPrev171 = x171;
            yPrev171 = y171;
            x171 += 0.15;
            y171 = isin_k_1[i] + isin_a_1[i] * asin(isin_b_1[i] * x171 + isin_c_1[i]);
        }
    }
}
void draw_cos_inv()
{

    double xPrev172, yPrev172, x172, y172;

    for (int i = 0; i < inum_trig_cos; i++)
    {

        xPrev172 = -100;
        yPrev172 = icos_k_1[i] + icos_a_1[i] * acos(icos_b_1[i] * xPrev172 + icos_c_1[i]);

        x172 = xPrev172;
        y172 = icos_k_1[i] + icos_a_1[i] * acos(icos_b_1[i] * x172 + icos_c_1[i]);
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {

            iLine(xPrev172 * 30 + Ox - diff_x, yPrev172 * 30 - diff_y + Oy, x172 * 30 + Ox - diff_x, y172 * 30 + Oy - diff_y);
            iLine(xPrev172 * 30 + Ox - diff_x + 1, yPrev172 * 30 + .25 - diff_y + Oy, x172 * 30 + Ox - diff_x + 0.25, y172 * 30 + Oy + 1 - diff_y);
            iLine(xPrev172 * 30 + Ox - diff_x - 1, yPrev172 * 30 - .25 - diff_y + Oy, x172 * 30 + Ox - diff_x - 0.25, y172 * 30 - 1 + Oy - diff_y);

            xPrev172 = x172;
            yPrev172 = y172;
            x172 += 0.15;
            y172 = icos_k_1[i] + icos_a_1[i] * acos(icos_b_1[i] * x172 + icos_c_1[i]);
        }
    }
}
void draw_tan_inv()
{

    double xPrev173, yPrev173, x173, y173;

    for (int i = 0; i < inum_trig_tan; i++)
    {

        xPrev173 = -100;
        yPrev173 = itan_k_1[i] + itan_a_1[i] * (atan(itan_b_1[i] * xPrev173 + itan_c_1[i]));

        x173 = xPrev173;
        y173 = itan_k_1[i] + itan_a_1[i] * (atan(itan_b_1[i] * x173 + itan_c_1[i]));
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {

            iLine(xPrev173 * 30 + Ox - diff_x, yPrev173 * 30 - diff_y + Oy, x173 * 30 + Ox - diff_x, y173 * 30 + Oy - diff_y);
            iLine(xPrev173 * 30 + Ox - diff_x + 1, yPrev173 * 30 + .5 - diff_y + Oy, x173 * 30 + Ox - diff_x + 0.5, y173 * 30 + Oy + 1 - diff_y);
            iLine(xPrev173 * 30 + Ox - diff_x - 1, yPrev173 * 30 - .5 - diff_y + Oy, x173 * 30 + Ox - diff_x - 0.5, y173 * 30 - 1 + Oy - diff_y);

            xPrev173 = x173;
            yPrev173 = y173;
            x173 += 0.15;
            y173 = itan_k_1[i] + itan_a_1[i] * (atan(itan_b_1[i] * x173 + itan_c_1[i]));
        }
    }
}
void draw_cosec_inv_half()
{

    double xPrev174, yPrev174, x174, y174;

    for (int i = 0; i < inum_trig_cosec; i++)
    {

        xPrev174 = -100;
        // yPrev174 = icosec_k_1[i] + icosec_a_1[i] * 1 / asin(icosec_b_1[i] * xPrev174 + icosec_c_1[i]);
        yPrev174 = icosec_k_1[i] + icosec_a_1[i] *  asin(1/(icosec_b_1[i] * xPrev174 + icosec_c_1[i]));

        x174 = xPrev174;
        // y174 = icosec_k_1[i] + icosec_a_1[i] * 1 / asin(icosec_b_1[i] * x174 + icosec_c_1[i]);
        y174 = icosec_k_1[i] + icosec_a_1[i] *  asin(1/(icosec_b_1[i] * x174 + icosec_c_1[i]));
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {
            if (yPrev174 > y174)
            {
                iLine(xPrev174 * 30 + Ox - diff_x, yPrev174 * 30 - diff_y + Oy, x174 * 30 + Ox - diff_x, y174 * 30 + Oy - diff_y);
                iLine(xPrev174 * 30 + Ox - diff_x + 1, yPrev174 * 30 + .5 - diff_y + Oy, x174 * 30 + Ox - diff_x + 0.5, y174 * 30 + Oy + 1 - diff_y);
                iLine(xPrev174 * 30 + Ox - diff_x - 1, yPrev174 * 30 - .5 - diff_y + Oy, x174 * 30 + Ox - diff_x - 0.5, y174 * 30 - 1 + Oy - diff_y);
            }

            xPrev174 = x174;
            yPrev174 = y174;
            x174 += 0.1;
            //y174 = icosec_k_1[i] + icosec_a_1[i] * 1 / asin(icosec_b_1[i] * x174 + icosec_c_1[i]);
            y174 = icosec_k_1[i] + icosec_a_1[i] *  asin(1/(icosec_b_1[i] * x174 + icosec_c_1[i]));
        }
    }
}
void draw_cosec_inv_otherhalf()
{

    double xPrev174, yPrev174, x174, y174;

    for (int i = 0; i < inum_trig_cosec; i++)
    {

        xPrev174 = -100;
        yPrev174 = icosec_k_1[i] + icosec_a_1[i] *  asin(1 /(icosec_b_1[i] * xPrev174 + icosec_c_1[i]));

        x174 = xPrev174;
        y174 = icosec_k_1[i] + icosec_a_1[i] * asin(1/(icosec_b_1[i] * x174 + icosec_c_1[i]));
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {
            if (yPrev174 > y174)
            {
                iLine(xPrev174 * 30 + Ox - diff_x, yPrev174 * 30 - diff_y + Oy, x174 * 30 + Ox - diff_x, y174 * 30 + Oy - diff_y);
                iLine(xPrev174 * 30 + Ox - diff_x + 1, yPrev174 * 30 + .5 - diff_y + Oy, x174 * 30 + Ox - diff_x + 0.5, y174 * 30 + Oy + 1 - diff_y);
                iLine(xPrev174 * 30 + Ox - diff_x - 1, yPrev174 * 30 - .5 - diff_y + Oy, x174 * 30 + Ox - diff_x - 0.5, y174 * 30 - 1 + Oy - diff_y);
            }

            xPrev174 = x174;
            yPrev174 = y174;
            x174 += 0.15;
            y174 = icosec_k_1[i] + icosec_a_1[i] *  asin(1 /(icosec_b_1[i] * x174 + icosec_c_1[i]));
        }
    }
}
void draw_sec_inv()
{

    double xPrev175, yPrev175, x175, y175;

    for (int i = 0; i < inum_trig_sec; i++)
    {

        xPrev175 = -100;
        yPrev175 = isec_k_1[i] + isec_a_1[i] *  acos(1 /(isec_b_1[i] * xPrev175 + isec_c_1[i]));

        x175 = xPrev175;
        y175 = isec_k_1[i] + isec_a_1[i] *acos(1/(isec_b_1[i] * x175 + isec_c_1[i]));
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {

            iLine(xPrev175 * 30 + Ox - diff_x, yPrev175 * 30 - diff_y + Oy, x175 * 30 + Ox - diff_x, y175 * 30 + Oy - diff_y);
            iLine(xPrev175 * 30 + Ox - diff_x + 1, yPrev175 * 30 + .5 - diff_y + Oy, x175 * 30 + Ox - diff_x + 0.5, y175 * 30 + Oy + 1 - diff_y);
            iLine(xPrev175 * 30 + Ox - diff_x - 1, yPrev175 * 30 - .5 - diff_y + Oy, x175 * 30 + Ox - diff_x - 0.5, y175 * 30 - 1 + Oy - diff_y);

            xPrev175 = x175;
            yPrev175 = y175;
            x175 += 0.1;
            y175 = isec_k_1[i] + isec_a_1[i] * acos(1/(isec_b_1[i] * x175 + isec_c_1[i]));
        }
    }
}
void draw_cot_inv_half()
{

    double xPrev176, yPrev176, x176, y176;

    for (int i = 0; i < inum_trig_cot; i++)
    {

        xPrev176 = -100;
        yPrev176 = icot_k_1[i] + icot_a_1[i] * (atan(1/(icot_b_1[i] * xPrev176 + icot_c_1[i])));

        x176 = xPrev176;
        y176 = icot_k_1[i] + icot_a_1[i] * (atan(1/(icot_b_1[i] * x176 + icot_c_1[i])));
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {
            if (yPrev176 > y176)
            {
                iLine(xPrev176 * 30 + Ox - diff_x, yPrev176 * 30 - diff_y + Oy, x176 * 30 + Ox - diff_x, y176 * 30 + Oy - diff_y);
                iLine(xPrev176 * 30 + Ox - diff_x + 1, yPrev176 * 30 + .5 - diff_y + Oy, x176 * 30 + Ox - diff_x + 0.5, y176 * 30 + Oy + 1 - diff_y);
                iLine(xPrev176 * 30 + Ox - diff_x - 1, yPrev176 * 30 - .5 - diff_y + Oy, x176 * 30 + Ox - diff_x - 0.5, y176 * 30 - 1 + Oy - diff_y);
            }

            xPrev176 = x176;
            yPrev176 = y176;
            x176 += 0.0915;
            y176 = icot_k_1[i] + icot_a_1[i] * (atan(1/(icot_b_1[i] * x176 + icot_c_1[i])));
        }
    }
}
void draw_cot_inv_otherhalf()
{

    double xPrev176, yPrev176, x176, y176;

    for (int i = 0; i < inum_trig_cot; i++)
    {

        xPrev176 = -100;
        yPrev176 = icot_k_1[i] + icot_a_1[i] * (atan(1/(icot_b_1[i] * xPrev176 + icot_c_1[i])));

        x176 = xPrev176;
        y176 = icot_k_1[i] + icot_a_1[i] * (atan(1/(icot_b_1[i] * x176 + icot_c_1[i])));
        int temp = i % 5;
        if (darkmode)
            iSetColor(red_dark[temp], green_dark[temp], blue_dark[temp]);
        else
            iSetColor(red[temp], green[temp], blue[temp]);
        for (int j = 0; j <= 1500; j++)
        {
            if (yPrev176 > y176)
            {
                iLine(xPrev176 * 30 + Ox - diff_x, yPrev176 * 30 - diff_y + Oy, x176 * 30 + Ox - diff_x, y176 * 30 + Oy - diff_y);
                iLine(xPrev176 * 30 + Ox - diff_x + 1, yPrev176 * 30 + .5 - diff_y + Oy, x176 * 30 + Ox - diff_x + 0.5, y176 * 30 + Oy + 1 - diff_y);
                iLine(xPrev176 * 30 + Ox - diff_x - 1, yPrev176 * 30 - .5 - diff_y + Oy, x176 * 30 + Ox - diff_x - 0.5, y176 * 30 - 1 + Oy - diff_y);
            }

            xPrev176 = x176;
            yPrev176 = y176;
            x176 += 0.092;
            y176 = icot_k_1[i] + icot_a_1[i] * (atan(1/(icot_b_1[i] * x176 + icot_c_1[i])));
        }
    }
}
void iDraw()
{

    iClear();
    // Background

    if (darkmode)
        iSetColor(0, 0, 0);
    else
        iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, console_x, 1000);

    // size of console
    double x_max = console_x;
    double y_max = console_y;

    // scaling
    double x = -10035 - 90, y = -10023;

    // y_grid
    for (int i = 0; i < num_grids; i++)
    {
        if (darkmode)
            iSetColor(255, 255, 255);
        else
            iSetColor(0, 0, 0);
        iLine(x - diff_x, -10000 - diff_y, x - diff_x, 100000 - diff_y);
        if (i % 5 == 0)
        {
            double k = x;
            iLine(k + 0.5 - diff_x, -10000 - diff_y, k + 0.5 - diff_x, 100000 - diff_y);
        }
        x += 30;
    }

    // x_grid
    for (int j = 0; j < num_grids; j++)
    {
        if (darkmode)
            iSetColor(255, 255, 255);
        else
            iSetColor(0, 0, 0);
        iLine(-10000 - diff_x, y - diff_y, 10000 - diff_x, y - diff_y);
        if (j % 5 == 0)
        {
            double k = y;
            iLine(-10000 - diff_x, k + 1 - diff_y, 10000 - diff_x, k + 1 - diff_y);
        }
        y += 30;
    }

    // y-axis
    // iSetColor(255, 0, 0);
    if (darkmode)
        iSetColor(255, 255, 255);
    else
        iSetColor(0, 0, 0);
    iLine(x_max / 2 + 1 - diff_x, -100000 - diff_y, x_max / 2 + 1 - diff_x, 100000 - diff_y);
    iLine(x_max / 2 - 1 - diff_x, -100000 - diff_y, x_max / 2 - 1 - diff_x, 100000 - diff_y);
    iLine(x_max / 2 - diff_x, -100000 - diff_y, x_max / 2 - diff_x, 100000 - diff_y);

    // x-axis
    // iSetColor(0, 0, 255);
    if (darkmode)
        iSetColor(255, 255, 255);
    else
        iSetColor(0, 0, 0);
    iLine(-100000 - diff_x, y_max / 2 - diff_y, 100000 - diff_x, y_max / 2 - diff_y);
    iLine(-100000 - diff_x, y_max / 2 + 1 - diff_y, 100000 - diff_x, y_max / 2 + 1 - diff_y);
    iLine(-100000 - diff_x, y_max / 2 + 2 - diff_y, 100000 - diff_x, y_max / 2 + 2 - diff_y);

    // x-axis
    // positive points
    double x_beginning1 = 820;
    for (int i = 1; i < num_grids; i++)
    {
        double t = 5 * i;
        char numStr[3];
        sprintf(numStr, "%0.0lf", t);
        if (darkmode)
            iSetColor(0, 0, 0);
        else
            iSetColor(255, 255, 255);

        // default
        if ((Oy - 10 + diff_y) > 0 && (Oy - 10 + diff_y) < 680)
        {
            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(x_beginning1 - diff_x, Oy - 20 - diff_y, numStr, GLUT_BITMAP_HELVETICA_18);
            x_beginning1 += 150;
        }

        // top stop
        else if ((Oy - 10 + diff_y) < 0)
        {
            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(x_beginning1 - diff_x + 5, 660, numStr, GLUT_BITMAP_HELVETICA_18);
            x_beginning1 = x_beginning1 + 150;
        }

        // bottom stop
        else if ((Oy - 10 - diff_y) < 0)
        {
            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(x_beginning1 - diff_x, 0, numStr, GLUT_BITMAP_HELVETICA_18);
            x_beginning1 = x_beginning1 + 150;
        }
    }

    // negative points
    double x_beginning2 = 520;
    for (int i = 1; i < num_grids; i++)
    {
        double t = -5 * i;
        char numStr[3];
        sprintf(numStr, "%0.0lf", t);
        if (darkmode)
            iSetColor(0, 0, 0);
        else
            iSetColor(255, 255, 255);

        if ((Oy - 10 + diff_y) > 0 && (Oy - 10 + diff_y) < 680)
        {
            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(x_beginning2 - diff_x - 10, Oy - 20 - diff_y, numStr, GLUT_BITMAP_HELVETICA_18);
            x_beginning2 = x_beginning2 - 150;
        }

        // top stop
        else if ((Oy - 10 + diff_y) < 0)
        {
            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(x_beginning2 - diff_x, 660, numStr, GLUT_BITMAP_HELVETICA_18);
            x_beginning2 = x_beginning2 - 150;
        }

        // bottom stop
        else if ((Oy - 10 - diff_y) < 0)
        {
            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(x_beginning2 - diff_x, 0, numStr, GLUT_BITMAP_HELVETICA_18);
            x_beginning2 = x_beginning2 - 150;
        }
    }

    // y-axis
    // positive points
    double y_beginning1 = Oy / 2 + 3;
    for (int i = 0; i < num_grids; i++)
    {
        double t = 5 * i;
        char numStr[3];
        sprintf(numStr, "%0.0lf", t);

        // default
        if (Ox - 10 + diff_x < 1350 && Ox - 10 + diff_x > 0)
        {
            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(Ox - 10 - diff_x, y_beginning1 + 140 - diff_y, numStr, GLUT_BITMAP_HELVETICA_18);
            y_beginning1 += 150;
        }

        // right stop
        else if ((Ox - 10 + diff_x) < 0)
        {
            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(1335, y_beginning1 + 150 - diff_y, numStr, GLUT_BITMAP_HELVETICA_18);
            y_beginning1 += 150;
        }

        // left stop
        else if ((Ox - 10 - diff_x) < 0)
        {
            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(0, y_beginning1 + 150 - diff_y, numStr, GLUT_BITMAP_HELVETICA_18);
            y_beginning1 += 150;
        }
    }

    // negative points
    double y_beginning2 = Oy / 2;
    for (int i = 1; i < num_grids; i++)
    {
        double t = -5 * i;
        char numStr[3];
        sprintf(numStr, "%0.0lf", t);

        // default
        if (Ox - 10 + diff_x < 1350 && Ox - 10 + diff_x > 0)
        {
            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(Ox - 15 - diff_x, y_beginning2 - diff_y, numStr, GLUT_BITMAP_HELVETICA_18);
            y_beginning2 -= 150;
        }

        // right stop
        else if ((Ox - 10 + diff_x) < 0)
        {
            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(1320, y_beginning2 - diff_y, numStr, GLUT_BITMAP_HELVETICA_18);
            y_beginning2 -= 150;
        }

        // left stop
        else if ((Ox - 10 - diff_x) < 0)
        {

            if (darkmode)
                iSetColor(255, 255, 255);
            else
                iSetColor(0, 0, 0);
            iText(0, y_beginning2 - diff_y, numStr, GLUT_BITMAP_HELVETICA_18);
            y_beginning2 -= 150;
        }
    }

    drawline();
    drawcircle();
    Ellipse();

    drawCurvePositive();
    drawCurveNegative();
    draw_QuadCurve_Positive();
    draw_QuadCurve_Negative();

    draw_Curve_Positive();
    draw_Curve_Negative();

    draw__Curve__Positive();
    draw__Curve__Negative();

    draw_Curve_Horizontal_Parabola_Positive();
    draw_Curve_Horizontal_Parabola_Negative();

    draw_exponentialcurve1();
    draw_exponentialcurve2();
    draw_exponentialcurve3();
    draw_exponentialcurve4();

    drawHyperbolaUpper();
    drawHyperbolaLower();

    draw_logarithmic_151();
    draw_logarithmic_152();

    draw_sin();
    draw_cos();
    draw_tan();

    draw_cosec_half();
    draw_cosec_otherhalf();

    draw_sec_half();
    draw_sec_otherhalf();

    draw_cot();

    draw_sin_inv();
    draw_cos_inv();
    draw_tan_inv();

    draw_cosec_inv_half();
    draw_cosec_inv_otherhalf();

    draw_sec_inv();

    draw_cot_inv_otherhalf();
    draw_cot_inv_half();

    if (mode == 1) // text box for choosing what to draw
    {
        drawboxInput1stwindow();
        iSetColor(255, 255, 255);
        iText(5, 380 + 120, str);
    }
    if (mode == 11) // text box for what type of sl to draw
    {
        SL_1st_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 210, str);
        flag11 = 1;
    }
    if (mode == 111) // for y=mx+c

    {

        SL_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230, str);
        flag111 = 1;
    }
    if (mode == 112) // for x/a+y/b=1
    {

        SL_2_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230, str);
        flag112 = 1;
    }
    if (mode == 113) // for(y-y1)=m(x-x1)
    {

        SL_3_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230, str);
        flag113 = 1;
    }
    if (mode == 12) // Quadratic equations

    {

        QUAD_1st_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 210, str);
        flag12 = 1;
    }
    if (mode == 121) // for y=ax^2+bx+c

    { 

        QUAD_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230, str);
        flag121 = 1;
    }
    if (mode == 122) // for y=a(x-h)^2+k

    {

        QUAD_2_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230, str);
        flag122 = 1;
    }
    if (mode == 123) // for y = a(x - R1)(x - R2)

    {

        QUAD_3_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230, str);
        flag123 = 1;
    }
    if (mode == 13) // FOR CONICS
    {

        CONICS_1st_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 160, str);
        flag13 = 1;
    }
    if (mode == 131) // FOR CIRCLES

    {

        CONICS_Circle_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230, str);
        flag131 = 1;
    }
    if (mode == 1311) // FOR CIRCLES OF THE FORM(x - h) ^ 2 + (y - k) ^ 2 = r ^ 2

    {
        CONICS_Circle_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 210, str);
        flag1311 = 1;
    }
    if (mode == 1312) // FOR CIRCLES OF THE FORM x^2 + y^2 + 2gx + 2fy + c = 0

    {

        CONICS_Circle_2_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 210, str);
        flag1312 = 1;
    }
    if (mode == 132) // FOR PARABOLAS

    {

        CONICS_Parabola_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 210, str);
        flag132 = 1;
    }
    if (mode == 1321) // FOR A PARABOLA OF THE FORM  y = a(x-h)^2+k

    {

        CONICS_Parabola_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 210, str);
        flag1321 = 1;
    }
    if (mode == 1322) // FOR A PARABOLA OF THE FORM x = a(y-k)^2 +h

    {
        CONICS_Parabola_2_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 210, str);
        flag1322 = 1;
    }
    if (mode == 133) // FOR ELLIPSES

    {

        CONICS_Ellipse_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230, str);
        flag133 = 1;
    }
    if (mode == 134) //  FOR HYPERBOLAS

    {

        CONICS_Hyperbola_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230, str);
        flag134 = 1;
    }
    if (mode == 14) // FOR EXPONENTIAL EQUATIONS

    {

        EXPONENTIAL_1st_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag14 = 1;
    }
    if (mode == 141)
    {

        EXPONENTIAL_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 220, str);
        flag141 = 1;
    }
    if (mode == 142)
    {

        EXPONENTIAL_2_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 220, str);
        flag142 = 1;
    }
    if (mode == 143)
    {

        EXPONENTIAL_3_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 220, str);
        flag143 = 1;
    }
    if (mode == 144)
    {

        EXPONENTIAL_4_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 220, str);
        flag144 = 1;
    }
    if (mode == 15) // FOR Logarithmic EQUATIONS

    {
        LOGARITHMIC_1st_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag15 = 1;
    }
    if (mode == 151)
    {
        LOGARITHMIC_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag151 = 1;
    }
    if (mode == 152)
    {
        LOGARITHMIC_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag152 = 1;
    }
    if (mode == 16) // FOR Trigonometric EQUATIONS
    {
        Trigonometric_1st_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 60, str);
        flag16 = 1;
    }
    if (mode == 161)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag161 = 1;
    }
    if (mode == 162)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag162 = 1;
    }
    if (mode == 163)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag163 = 1;
    }
    if (mode == 164)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag164 = 1;
    }
    if (mode == 165)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag165 = 1;
    }
    if (mode == 166)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag166 = 1;
    }
    if (mode == 17) // FOR Inverse Trigonometric EQUATIONS
    {
        Inverse_Trigonometric_1st_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 60, str);
        flag17 = 1;
    }
    if (mode == 171)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag171 = 1;
    }
    if (mode == 172)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag172 = 1;
    }
    if (mode == 173)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag173 = 1;
    }
    if (mode == 174)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag174 = 1;
    }
    if (mode == 175)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag175 = 1;
    }
    if (mode == 176)
    {
        Trigonometric_1_window();
        iSetColor(255, 255, 255);
        iText(5, 380 + 230 - 50, str);
        flag176 = 1;
    }

    iShowBMP(1300, 625, "darkmode2.bmp");
    if (mode == 0)
    {
        iShowBMP(15, 625, "rightarrow.bmp");
    }
    if (mode)
    {
        iShowBMP(570, 620, "leftarrow.bmp");
    }
    if (diff_x || diff_y)
    {
        iShowBMP(1300, 510, "center.bmp");
    }
    
    if (title_screen == 1)
    {
        main_menu();
    }
}
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        if (mx >= 0 && mx <= 1350 && my >= 0 && my <= 680 && mode == 0)
        {
            d = mx;
            e = my;
            //printf("mx = %d, my = %d\n", mx, my);
        }
        if (mx >= 1300 && mx <= 1327 && my >= 625 && my <= 655)
        {
            if (darkmode == 0)
                darkmode = 1;
            else
                darkmode = 0;
        }
        if (mx >= 15 && mx <= 40 && my >= 625 && my <= 650)
        {
            mode = 1;
        }
        if (mode && mx >= 570 && mx <= 590 && my >= 620 && my <= 640)
        {
            mode = 0;
        }
        if (title_screen == 1 && mx >= 400 && mx < 930 && my >= 200 && my <= 270)
        {
            title_screen = 0;
        }
        if (diff_x && mx >= 1300 && mx < 1300 + 35 && my >= 510 && my <= 510 + 35)
        {
            diff_x = 0;
            diff_y = 0;
            
        }
        
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        mode = 1;
        d = mx;
        e = my;
    }
    
}

void iMouseMove(int mx, int my)
{

    a = mx;
    b = my;

    diff_x += (d - a);
    diff_y += (e - b);
    d = a;
    e = b;
}

void iKeyboard(unsigned char key)
{
    int i;
    if (mode == 1) // initial text box
    {
        if (key == '\r')
        {

            if (len == 1)
            {
                strcpy(str3, str);
            }

            else
                strcpy(str2, str);

            if (str3[0] == '1')
            {
                // straight line
                mode = 11;
            }

            if (str3[0] == '2')
            {
                // quadratic
                mode = 12;
            }
            if (str3[0] == '3')
            {
                // conics
                mode = 13;
            }
            if (str3[0] == '4')
            {
                // exponential
                mode = 14;
            }
            if (str3[0] == '5')
            {
                // logarithmic
                mode = 15;
            }
            if (str3[0] == '6')
            {
                // logarithmic
                mode = 16;
            }
            if (str3[0] == '7')
            {
                // logarithmic
                mode = 17;
            }

            for (i = 0; i < len; i++)
            {
                str[i] = 0;
            }
            len = 0;
        }

        else
        {
            str[len] = key;
            len++;
        }
    }

    // for straight lines
    if (mode == 11)
    {

        if (flag11 == 1)
        {
            if (key == '\r')
            {

                if (len == 1)
                {
                    strcpy(str3, str);
                }

                else
                    strcpy(str2, str);

                if (str3[0] == '1')
                {

                    mode = 111;
                    flag11 = 0;
                }

                if (str3[0] == '2')
                {
                    mode = 112;
                    flag11 = 0;
                }
                if (str3[0] == '3')
                {
                    mode = 113;
                    flag11 = 0;
                }

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;
            }

            else
            {
                str[len] = key;
                len++;
            }
        }
    }
    if (mode == 111) // Straight line-1
    {

        if (key == '\r')
        {
            double c, m;

            if (flag111 == 1)
            {

                sscanf(str, "%lf %lf", &m, &c);
                a1[num_lines] = 30 * (-1000) + Ox;
                b1[num_lines] = (m * (-1000) + c) * 30 + Oy;
                a2[num_lines] = 30 * (1000) + Ox;
                b2[num_lines] = (m * (1000) + c) * 30 + Oy;
                num_lines++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;
                mode = 0;
                flag111 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 112) // Straight line-2
    {
        if (key == '\r')
        {
            double p, q;

            if (flag112 == 1)
            {

                sscanf(str, "%lf %lf", &p, &q);
                a1[num_lines] = (-1000) * 30 + Ox;
                b1[num_lines] = ((-q / p) * (-1000) + q) * 30 + Oy;
                a2[num_lines] = 1000 * 30 + Ox;
                b2[num_lines] = ((-q / p) * (1000) + q) * 30 + Oy;

                num_lines++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;

                mode = 0;
                flag112 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 113) // Straight line-3
    {
        if (key == '\r')
        {
            double y1, x1, m;

            if (flag113 == 1)
            {

                sscanf(str, "%lf %lf %lf", &y1, &x1, &m);
                a1[num_lines] = (-1000) * 30 + Ox;
                b1[num_lines] = (y1 + m * (-1000 - x1)) * 30 + Oy;
                a2[num_lines] = (1000) * 30 + Ox;
                b2[num_lines] = (y1 + m * (1000 - x1)) * 30 + Oy;

                num_lines++;
                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;

                mode = 0;
                flag113 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }

    // FOR QUADRATIC EQUATIONS

    if (mode == 12)
    {

        if (flag12 == 1)
        {
            if (key == '\r')
            {

                if (len == 1)
                {
                    strcpy(str3, str);
                }

                else
                    strcpy(str2, str);

                if (str3[0] == '1')
                {

                    mode = 121;
                    flag12 = 0;
                }

                if (str3[0] == '2')
                {
                    mode = 122;
                    flag12 = 0;
                }
                if (str3[0] == '3')
                {
                    mode = 123;
                    flag12 = 0;
                }

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;
            }

            else
            {
                str[len] = key;
                len++;
            }
        }
    }
    if (mode == 121) // Quadratic-1
    {

        if (key == '\r')
        {
            double Aa, Bb, Cc;

            if (flag121 == 1)
            {

                sscanf(str, "%lf %lf %lf", &A[num_quad_curves], &B[num_quad_curves], &C[num_quad_curves]);

                num_quad_curves++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;
                mode = 0;
                flag121 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 122) // Quadratic-2
    {
        if (key == '\r')
        {

            if (flag122 == 1)
            {

                sscanf(str, "%lf %lf %lf", &constant_a122[num_quad_curves], &H122[num_quad_curves], &K122[num_quad_curves]);

                num_quad_curves++;
                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;

                mode = 0;
                flag122 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 123) // Quadratic-3
    {
        if (key == '\r')
        {

            if (flag123 == 1)
            {

                sscanf(str, "%lf %lf %lf", &constant_a2[num_quad_curves], &R1[num_quad_curves], &R2[num_quad_curves]);

                num_quad_curves++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;

                mode = 0;
                flag123 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }

    // FOR CONICS

    if (mode == 13)
    {

        if (flag13 == 1)
        {
            if (key == '\r')
            {

                if (len == 1)
                {
                    strcpy(str3, str);
                }

                else
                    strcpy(str2, str);

                if (str3[0] == '1')
                {

                    mode = 131;
                    flag13 = 0;
                }

                if (str3[0] == '2')
                {
                    mode = 132;
                    flag13 = 0;
                }
                if (str3[0] == '3')
                {
                    mode = 133;
                    flag13 = 0;
                }
                if (str3[0] == '4')
                {
                    mode = 134;
                    flag13 = 0;
                }

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;
            }

            else
            {
                str[len] = key;
                len++;
            }
        }
    }
    if (mode == 131)
    {

        if (flag131 == 1)
        {
            if (key == '\r')
            {

                if (len == 1)
                {
                    strcpy(str3, str);
                }

                else
                    strcpy(str2, str);

                if (str3[0] == '1')
                {

                    mode = 1311;
                    flag131 = 0;
                }

                if (str3[0] == '2')
                {
                    mode = 1312;
                    flag131 = 0;
                }

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;
            }

            else
            {
                str[len] = key;
                len++;
            }
        }
    }
    if (mode == 1311) // Circle-1
    {
        if (key == '\r')
        {
            double a, b, c;

            if (flag1311 == 1)
            {

                sscanf(str, "%lf %lf %lf", &a, &b, &c);
                h[num_circles] = a * 30 + Ox;
                k[num_circles] = b * 30 + Oy;
                r[num_circles] = c * 30;

                num_circles++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;

                mode = 0;
                flag1311 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 1312) // Circle-2
    {
        if (key == '\r')
        {
            double g, f, q;

            if (flag1312 == 1)
            {

                sscanf(str, "%lf %lf %lf", &g, &f, &q);
                h[num_circles] = -g * 30 + Ox;
                k[num_circles] = -f * 30 + Oy;
                r[num_circles] = 30 * sqrt((g * g + f * f - q));

                num_circles++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;

                mode = 0;
                flag1312 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 132)
    {

        if (flag132 == 1)
        {
            if (key == '\r')
            {

                if (len == 1)
                {
                    strcpy(str3, str);
                }

                else
                    strcpy(str2, str);

                if (str3[0] == '1')
                {

                    mode = 1321;
                    flag132 = 0;
                }

                if (str3[0] == '2')
                {
                    mode = 1322;
                    flag132 = 0;
                }

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;
            }

            else
            {
                str[len] = key;
                len++;
            }
        }
    }
    if (mode == 1321) // Parabola-1
    {
        if (key == '\r')
        {

            if (flag1321 == 1)
            {

                sscanf(str, "%lf %lf %lf", &constant_a1[num_parabolas], &H1[num_parabolas], &K1[num_parabolas]);

                num_parabolas++;
                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;

                mode = 0;
                flag1321 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 1322) // Parabola-2
    {
        if (key == '\r')
        {

            if (flag1322 == 1)
            {

                sscanf(str, "%lf %lf %lf", &constant_para[num_parabolas], &para2[num_parabolas], &para22[num_parabolas]);

                num_parabolas++;
                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;

                mode = 0;
                flag1322 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 133) // Ellipse
    {

        if (key == '\r')
        {
            double h, k, maj_axis, min_axis;

            if (flag133 == 1)
            {

                sscanf(str, "%lf %lf %lf %lf", &h, &k, &maj_axis, &min_axis);

                x1_ellipse[num_ellipses] = h * 30 + Ox;
                y1_ellipse[num_ellipses] = k * 30 + Oy;
                major_axis[num_ellipses] = maj_axis * 30;
                minor_axis[num_ellipses] = min_axis * 30;

                num_ellipses++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag133 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 134) // Hyperbola-1
    {
        if (key == '\r')
        {

            if (flag134 == 1)
            {

                sscanf(str, "%lf %lf %lf %lf", &HHyper[num_hyperbolas], &a_Hyper[num_hyperbolas], &KHyper[num_hyperbolas], &b_Hyper[num_hyperbolas]);
                num_hyperbolas++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag134 = 0;
            }
        }

        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 14) // EXPONENTIAL
    {

        if (flag14 == 1)
        {
            if (key == '\r')
            {

                if (len == 1)
                {
                    strcpy(str3, str);
                }

                else
                    strcpy(str2, str);

                if (str3[0] == '1')
                {

                    mode = 141;
                    flag14 = 0;
                }

                if (str3[0] == '2')
                {
                    mode = 142;
                    flag14 = 0;
                }
                if (str3[0] == '3')
                {

                    mode = 143;
                    flag14 = 0;
                }
                if (str3[0] == '4')
                {

                    mode = 144;
                    flag14 = 0;
                }

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;
            }

            else
            {
                str[len] = key;
                len++;
            }
        }
    }
    if (mode == 141)
    {

        if (key == '\r')
        {

            if (flag141 == 1)
            {
                sscanf(str, "%lf", &expo_k[num_expo_curves_1]);
                num_expo_curves_1++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag141 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 142)
    {

        if (key == '\r')
        {

            if (flag142 == 1)
            {
                sscanf(str, "%lf", &expo_k2[num_expo_curves_2]);
                num_expo_curves_2++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag142 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 143)
    {

        if (key == '\r')
        {
            if (flag143 == 1)
            {
                sscanf(str, "%lf %lf", &expo_k3[num_expo_curves_3], &base3[num_expo_curves_3]);
                num_expo_curves_3++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag143 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 144)
    {

        if (key == '\r')
        {
            if (flag144 == 1)
            {
                sscanf(str, "%lf %lf", &expo_k4[num_expo_curves_4], &base4[num_expo_curves_4]);
                num_expo_curves_4++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag144 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 15) // LOGARITHMIC
    {

        if (flag15 == 1)
        {
            if (key == '\r')
            {

                if (len == 1)
                {
                    strcpy(str3, str);
                }

                else
                    strcpy(str2, str);

                if (str3[0] == '1')
                {

                    mode = 151;
                    flag15 = 0;
                }

                if (str3[0] == '2')
                {
                    mode = 152;
                    flag15 = 0;
                }

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;
            }

            else
            {
                str[len] = key;
                len++;
            }
        }
    }
    if (mode == 151)
    {

        if (key == '\r')
        {

            if (flag151 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &log_k_1[num_log1], &log_a_1[num_log1], &log_b_1[num_log1], &log_c_1[num_log1]);
                num_log1++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag151 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 152)
    {

        if (key == '\r')
        {

            if (flag152 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &log_kk[num_log2], &log_aa[num_log2], &log_bb[num_log2], &log_cc[num_log2]);
                num_log2++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag152 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 16) // TRIGONOMETRIC
    {

        if (flag16 == 1)
        {
            if (key == '\r')
            {

                if (len == 1)
                {
                    strcpy(str3, str);
                }

                else
                    strcpy(str2, str);

                if (str3[0] == '1')
                {

                    mode = 161;
                    flag16 = 0;
                }

                if (str3[0] == '2')
                {
                    mode = 162;
                    flag16 = 0;
                }
                if (str3[0] == '3')
                {

                    mode = 163;
                    flag16 = 0;
                }

                if (str3[0] == '4')
                {
                    mode = 164;
                    flag16 = 0;
                }
                if (str3[0] == '5')
                {

                    mode = 165;
                    flag16 = 0;
                }

                if (str3[0] == '6')
                {
                    mode = 166;
                    flag16 = 0;
                }

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;
            }

            else
            {
                str[len] = key;
                len++;
            }
        }
    }
    if (mode == 161)
    {

        if (key == '\r')
        {

            if (flag161 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &sin_k_1[num_trig_sin], &sin_a_1[num_trig_sin], &sin_b_1[num_trig_sin], &sin_c_1[num_trig_sin]);
                num_trig_sin++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag161 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 162)
    {

        if (key == '\r')
        {

            if (flag162 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &cos_k_1[num_trig_cos], &cos_a_1[num_trig_cos], &cos_b_1[num_trig_cos], &cos_c_1[num_trig_cos]);
                num_trig_cos++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag162 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 163)
    {

        if (key == '\r')
        {

            if (flag163 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &tan_k_1[num_trig_tan], &tan_a_1[num_trig_tan], &tan_b_1[num_trig_tan], &tan_c_1[num_trig_tan]);
                num_trig_tan++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag163 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 164)
    {

        if (key == '\r')
        {

            if (flag164 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &cosec_k_1[num_trig_cosec], &cosec_a_1[num_trig_cosec], &cosec_b_1[num_trig_cosec], &cosec_c_1[num_trig_cosec]);
                num_trig_cosec++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag164 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 165)
    {

        if (key == '\r')
        {

            if (flag165 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &sec_k_1[num_trig_sec], &sec_a_1[num_trig_sec], &sec_b_1[num_trig_sec], &sec_c_1[num_trig_sec]);
                num_trig_sec++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag165 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 166)
    {

        if (key == '\r')
        {

            if (flag166 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &cot_k_1[num_trig_cot], &cot_a_1[num_trig_cot], &cot_b_1[num_trig_cot], &cot_c_1[num_trig_cot]);
                num_trig_cot++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag166 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 17) // INVERSE TRIGONOMETRIC
    {

        if (flag17 == 1)
        {
            if (key == '\r')
            {

                if (len == 1)
                {
                    strcpy(str3, str);
                }

                else
                    strcpy(str2, str);

                if (str3[0] == '1')
                {

                    mode = 171;
                    flag17 = 0;
                }

                if (str3[0] == '2')
                {
                    mode = 172;
                    flag17 = 0;
                }
                if (str3[0] == '3')
                {

                    mode = 173;
                    flag17 = 0;
                }

                if (str3[0] == '4')
                {
                    mode = 174;
                    flag17 = 0;
                }
                if (str3[0] == '5')
                {

                    mode = 175;
                    flag17 = 0;
                }

                if (str3[0] == '6')
                {
                    mode = 176;
                    flag17 = 0;
                }

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }
                len = 0;
            }

            else
            {
                str[len] = key;
                len++;
            }
        }
    }
    if (mode == 171)
    {

        if (key == '\r')
        {

            if (flag171 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &isin_k_1[inum_trig_sin], &isin_a_1[inum_trig_sin], &isin_b_1[inum_trig_sin], &isin_c_1[inum_trig_sin]);
                inum_trig_sin++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag171 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 172)
    {

        if (key == '\r')
        {

            if (flag172 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &icos_k_1[inum_trig_cos], &icos_a_1[inum_trig_cos], &icos_b_1[inum_trig_cos], &icos_c_1[inum_trig_cos]);
                inum_trig_cos++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag172 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 173)
    {
        if (key == '\r')
        {

            if (flag173 == 1)
            {

                sscanf(str, "%lf %lf %lf %lf", &itan_k_1[inum_trig_tan], &itan_a_1[inum_trig_tan], &itan_b_1[inum_trig_tan], &itan_c_1[inum_trig_tan]);
                inum_trig_tan++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag173 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 174) ////does not work
    {

        if (key == '\r')
        {

            if (flag174 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &icosec_k_1[inum_trig_cosec], &icosec_a_1[inum_trig_cosec], &icosec_b_1[inum_trig_cosec], &icosec_c_1[inum_trig_cosec]);
                inum_trig_cosec++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag174 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 175)
    {

        if (key == '\r')
        {

            if (flag175 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &isec_k_1[inum_trig_sec], &isec_a_1[inum_trig_sec], &isec_b_1[inum_trig_sec], &isec_c_1[inum_trig_sec]);
                inum_trig_sec++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag175 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
    if (mode == 176)
    {

        if (key == '\r')
        {

            if (flag176 == 1)
            {
                sscanf(str, "%lf %lf %lf %lf", &icot_k_1[inum_trig_cot], &icot_a_1[inum_trig_cot], &icot_b_1[inum_trig_cot], &icot_c_1[inum_trig_cot]);
                inum_trig_cot++;

                for (i = 0; i < len; i++)
                {
                    str[i] = 0;
                }

                len = 0;
                mode = 0;
                flag176 = 0;
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
}

void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        if (mode && flag)
        {
            flag = 0;
            str3[0] = '\0';
        }
        else if (mode)
        {
            mode = 0;
            for (int i = 0; i < len; i++)
            {

                str[i] = 0;
            }
            len = 0;
        }
        else if (title_screen == 0)
        {
            title_screen = 1;
        }
        else
            exit(0);
    }
    if (key == GLUT_KEY_HOME)
    {
        if (num_lines > 0)
        {
            num_lines--;
            a1[num_lines] = {0}, a2[num_lines] = {0}, b1[num_lines] = {0}, b2[num_lines] = {0}; // straight line
        }
        if (num_circles > 0)
        {
            num_circles--;
            h[num_circles] = {0}, k[num_circles] = {0}, r[num_circles] = {0}; // circle
        }
        if (num_ellipses > 0)
        {
            num_ellipses--;
            x1_ellipse[num_ellipses] = {0}, y1_ellipse[num_ellipses] = {0}, major_axis[num_ellipses] = {0}, minor_axis[num_ellipses] = {0}; // ellipse
        }
        if (num_parabolas > 0)
        {
            num_parabolas--;
            H1[num_parabolas] = {0}, K1[num_parabolas] = {0}, constant_a1[num_parabolas] = {0};
            para2[num_parabolas] = {0}, para22[num_parabolas] = {0}, constant_para[num_parabolas] = {0}; // Quad y = a(x-k)^2+h
        }
        if (num_quad_curves > 0)
        {
            num_quad_curves--;
            R1[num_quad_curves] = {0}, R2[num_quad_curves] = {0}, constant_a2[num_quad_curves] = {0}; // Quad y = a (x-R1) (x-R2)

            A[num_quad_curves] = {0}, B[num_quad_curves] = {0}, C[num_quad_curves] = {0}; // Quad y =ax^2+bx+c

            H122[num_quad_curves] = {0}, K122[num_quad_curves] = {0}, constant_a122[num_quad_curves] = {0}; // Quad y = a(x-h)^2+k
        }
        if (num_expo_curves_1 > 0)
        {
            num_expo_curves_1--;
            expo_k[num_expo_curves_1] = {0};
        }
        if (num_expo_curves_2 > 0)
        {
            num_expo_curves_2--;
            expo_k2[num_expo_curves_2] = {0};
        }
        if (num_expo_curves_3 > 0)
        {
            num_expo_curves_3--;
            expo_k3[num_expo_curves_3] = {0}, base3[num_expo_curves_3] = {0};
        }
        if (num_expo_curves_4 > 0)
        {
            num_expo_curves_4--;
            expo_k4[num_expo_curves_4] = {0}, base4[num_expo_curves_4] = {0};
        }
        if (num_hyperbolas > 0)
        {
            num_hyperbolas--;
            HHyper[num_hyperbolas] = {0}, KHyper[num_hyperbolas] = {0}, a_Hyper[num_hyperbolas] = {0}, b_Hyper[num_hyperbolas] = {0};
        }
        if (num_hyperbolas2 > 0)
        {
            num_hyperbolas2--;
            HHyper2[num_hyperbolas2] = {0}, KHyper2[num_hyperbolas2] = {0}, a_Hyper2[num_hyperbolas2] = {0}, b_Hyper2[num_hyperbolas2] = {0};
        }
        if (num_log1 > 0)
        {
            num_log1--;
            log_k_1[num_log1] = {0}, log_a_1[num_log1] = {0}, log_b_1[num_log1] = {0}, log_c_1[num_log1] = {0};
        }
        if (num_log2 > 0)
        {
            num_log2--;
            log_kk[num_log2] = {0}, log_aa[num_log2] = {0}, log_bb[num_log2] = {0}, log_cc[num_log2] = {0};
        }
        if (num_trig_sin > 0)
        {
            num_trig_sin--;
            sin_k_1[num_trig_sin] = {0}, sin_a_1[num_trig_sin] = {0}, sin_b_1[num_trig_sin] = {0}, sin_c_1[num_trig_sin] = {0};
            
        }
        if (num_trig_cos > 0)
        {
            num_trig_cos--;
            cos_k_1[num_trig_cos] = {0}, cos_a_1[num_trig_cos] = {0}, cos_b_1[num_trig_cos] = {0}, cos_c_1[num_trig_cos] = {0};
            
        }
        if (num_trig_tan > 0)
        {
            num_trig_tan--;
            tan_k_1[num_trig_tan] = {0}, tan_a_1[num_trig_tan] = {0}, tan_b_1[num_trig_tan] = {0}, tan_c_1[num_trig_tan] = {0};
            
        }
        if (num_trig_cosec > 0)
        {
            num_trig_cosec--;
            cosec_k_1[num_trig_cosec] = {0}, cosec_a_1[num_trig_cosec] = {0}, cosec_b_1[num_trig_cosec] = {0}, cosec_c_1[num_trig_cosec] = {0};
            
        }
        if (num_trig_sec > 0)
        {
            num_trig_sec--;
            sec_k_1[num_trig_sec] = {0}, sec_a_1[num_trig_sec] = {0}, sec_b_1[num_trig_sec] = {0}, sec_c_1[num_trig_sec] = {0};
            
        }
        if (num_trig_cot > 0)
        {
            num_trig_cot--;
            cot_k_1[num_trig_cot] = {0}, cot_a_1[num_trig_cot] = {0}, cot_b_1[num_trig_cot] = {0}, cot_c_1[num_trig_cot] = {0};
            
        }
        

        if (inum_trig_sin > 0)
        {
            inum_trig_sin--;
            sin_k_1[inum_trig_sin] = {0}, sin_a_1[inum_trig_sin] = {0}, sin_b_1[inum_trig_sin] = {0}, sin_c_1[inum_trig_sin] = {0};
            
        }
        if (inum_trig_cos > 0)
        {
            inum_trig_cos--;
            cos_k_1[inum_trig_cos] = {0}, cos_a_1[inum_trig_cos] = {0}, cos_b_1[inum_trig_cos] = {0}, cos_c_1[inum_trig_cos] = {0};
            
        }
        if (inum_trig_tan > 0)
        {
            inum_trig_tan--;
            tan_k_1[inum_trig_tan] = {0}, tan_a_1[inum_trig_tan] = {0}, tan_b_1[inum_trig_tan] = {0}, tan_c_1[inum_trig_tan] = {0};
            
        }
        if (inum_trig_cosec > 0)
        {
            inum_trig_cosec--;
            cosec_k_1[inum_trig_cosec] = {0}, cosec_a_1[inum_trig_cosec] = {0}, cosec_b_1[inum_trig_cosec] = {0}, cosec_c_1[inum_trig_cosec] = {0};
            
        }
        if (inum_trig_sec > 0)
        {
            inum_trig_sec--;
            sec_k_1[inum_trig_sec] = {0}, sec_a_1[inum_trig_sec] = {0}, sec_b_1[inum_trig_sec] = {0}, sec_c_1[inum_trig_sec] = {0};
            
        }
        if (inum_trig_cot > 0)
        {
            inum_trig_cot--;
            cot_k_1[inum_trig_cot] = {0}, cot_a_1[inum_trig_cot] = {0}, cot_b_1[inum_trig_cot] = {0}, cot_c_1[inum_trig_cot] = {0};
            
        }
        
    }
}

int main()
{

    len = 0;
    mode = 0;
    flag = 0;
    str[0] = 0;
    iInitialize(1350, 680, "Graph Plotter");
}
