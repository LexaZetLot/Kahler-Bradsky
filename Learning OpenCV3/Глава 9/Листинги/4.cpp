 #include <GL/gl.h>
#include <GL/glu.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/opengl.hpp>

int rotx = 55, roty = 40;

void on_opengl(void* param)
{
    cv::ogl::Texture2D* backgroundTex = (cv::ogl::Texture2D*)param;
    glEnable(GL_TEXTURE_2D);
    backgroundTex->bind();
    cv::ogl::render(*backgroundTex);
    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -0.5);
    glRotatef(rotx, 1, 0, 0);
    glRotatef(roty, 0, 1, 0);
    glRotatef(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc (GL_LESS);
    static const int coords[6][4][3] =
    {
        { { +1, -1, -1 }, { -1, -1, -1 }, { -1, +1, -1 }, { +1, +1, -1 } },
        { { +1, +1, -1 }, { -1, +1, -1 }, { -1, +1, +1 }, { +1, +1, +1 } },
        { { +1, -1, +1 }, { +1, -1, -1 }, { +1, +1, -1 }, { +1, +1, +1 } },
        { { -1, -1, -1 }, { -1, -1, +1 }, { -1, +1, +1 }, { -1, +1, -1 } },
        { { +1, -1, +1 }, { -1, -1, +1 }, { -1, -1, -1 }, { +1, -1, -1 } },
        { { -1, -1, +1 }, { +1, -1, +1 }, { +1, +1, +1 }, { -1, +1, +1 } }
    };
    for (int i = 0; i < 6; ++i)
    {
        glColor3ub(i * 20, 100 + i * 10, i * 42);
        glBegin(GL_QUADS);
        for (int j = 0; j < 4; ++j)
            glVertex3d(0.2 * coords[i][j][0], 0.2 * coords[i][j][1], 0.2 * coords[i][j][2]);
        glEnd();
    }
}

void on_trackbar( int, void* )
{
    cv::updateWindow( "Example 9-4" );
}

int main()
{
    cv::Mat img = cv::imread("test.jpeg");
    cv::namedWindow( "Example 9-4", cv::WINDOW_OPENGL );
    cv::resizeWindow("Example 9-4", img.cols, img.rows);
    cv::createTrackbar( "X-rotation", "Example 9-4", &rotx, 360, on_trackbar);
    cv::createTrackbar( "Y-rotation", "Example 9-4", &roty, 360, on_trackbar);

    cv::ogl::Texture2D backgroundTex(img);
    cv::setOpenGlDrawCallback("Example 9-4", on_opengl, &backgroundTex);
    cv::updateWindow("Example 9-4");

    cv::waitKey(0);

    cv::setOpenGlDrawCallback("Example 9-4", 0, 0);
    cv::destroyAllWindows();

    return 0;
}
