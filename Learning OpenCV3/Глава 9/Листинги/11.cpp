class COpenCVTestView : public CWindowImpl<COpenCVTestView> 
{
public:
    DECLARE_WND_CLASS(NULL)
    bool OpenFile(std::string file);
    void _copyImage();
    BOOL PreTranslateMessage(MSG* pMsg);
    BEGIN_MSG_MAP(COpenCVTestView)
        MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
        MESSAGE_HANDLER(WM_PAINT, OnPaint)
        MESSAGE_HANDLER(WM_TIMER, OnTimer)
    END_MSG_MAP()
//  Handler prototypes (uncomment arguments if needed):
//   LRESULT MessageHandler(
//    UINT    /*uMsg*/,
//    WPARAM  /*wParam*/,
//    LPARAM  /*lParam*/,
//    BOOL&   /*bHandled*/
//  );
//  LRESULT CommandHandler(
//    WORD    /*wNotifyCode*/,
//    WORD    /*wID*/,
//    HWND    /*hWndCtl*/,
//    BOOL&   /*bHandled*/
//  );
//  LRESULT NotifyHandler(
//    int     /*idCtrl*/,
//    LPNMHDR /*pnmh*/,
//    BOOL&   /*bHandled*/
//  );
    LRESULT OnPaint(
        UINT    /*uMsg*/,
        WPARAM  /*wParam*/,
        LPARAM  /*lParam*/,
        BOOL&   /*bHandled*/
    );
    LRESULT OnTimer(
        UINT    /*uMsg*/,
        WPARAM  /*wParam*/,
        LPARAM  /*lParam*/,
        BOOL&   /*bHandled*/
    );
    LRESULT OnEraseBkgnd(
        UINT    /*uMsg*/,
        WPARAM  /*wParam*/,
        LPARAM  /*lParam*/,
        BOOL&   /*bHandled*/
    );
private:
    cv::VideoCapture m_cap;
    cv::Mat          m_cv_img;
    RGBTRIPLE*       m_bitmapBits;
};

LRESULT CMainFrame::OnFileOpen(
    WORD /*wNotifyCode*/,
    WORD /*wID*/,
    HWND /*hWndCtl*/,
    BOOL& /*bHandled*/
    ) {
    WTL::CFileDialog dlg(TRUE);
    if (IDOK == dlg.DoModal(m_hWnd)) 
        m_view.OpenFile(dlg.m_szFileName);
    
    return 0;
}

bool COpenCVTestView::OpenFile(std::string file) 
{
    if(!m_cap.open(file)) 
        return false;
    // Если файл удалось открыть, выполняем настройку
    m_cap.read( m_cv_img );
    // Можно было бы создать здесь DIBSection, но мы просто выделим память
    // для битовой карты
    m_bitmapBits = new RGBTRIPLE[m_cv_img.cols * m_cv_img.rows];
    _copyImage();
    SetTimer(0, 1000.0f / m_cap.get(cv::CAP_PROP_FPS));
    return true;
}

void COpenCVTestView::_copyImage() 
{
    // Скопировать данные изображения в битовую карту
    cv::Mat cv_header_to_qt_image(
        cv::Size(
            m_cv_img.cols,
            m_cv_img.rows
        ),
        CV_8UC3,
        m_bitmapBits
  );
  cv::cvtColor(m_cv_img, cv_header_to_qt_image, cv::BGR2RGB);
}

LRESULT COpenCVTestView::OnPaint(
    UINT   /*uMsg*/,
    WPARAM /*wParam*/,
    LPARAM /*lParam*/,
    BOOL&  /*bHandled*/
) {
    CPaintDC dc(m_hWnd);
    WTL::CRect rect;
    GetClientRect(&rect);
    if(m_cap.isOpened()) 
    {
        BITMAPINFO bmi = {0};
        bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
        bmi.bmiHeader.biCompression = BI_RGB;
        bmi.bmiHeader.biWidth
        = m_cv_img.cols;
        // По умолчанию битовые карты заполняются снизу вверх
        // Чтобы изменить направление на противоположное, нужно
        // задать отрицательную высоту
        bmi.bmiHeader.biHeight = m_cv_img.rows * -1;
        bmi.bmiHeader.biPlanes = 1;
        bmi.bmiHeader.biBitCount = 24; // 32, если используется RGBQUAD
        dc.StretchDIBits(
            0,
            rect.Width(),
            0,
            bmi.bmiHeader.biWidth,
            m_bitmapBits,
            &bmi,
            DIB_RGB_COLORS,
            SRCCOPY
            0,
            rect.Height(),
            0,
            abs(bmi.bmiHeader.biHeight),
            Working with Windows
            | 245
        );
    } 
    else 
        dc.FillRect(rect, COLOR_WINDOW);
    return 0;
}

RESULT COpenCVTestView::OnTimer(
    UINT    /*uMsg*/,
    WPARAM  /*wParam*/,
    LPARAM  /*lParam*/,
    BOOL&   /*bHandled*/
) {
    // Ничего не делать, если обьект захвата не открыт
    if(!m_cap.isOpened()) 
        return 0;
    m_cap.read(m_cv_img);
    _copyImage();
    Invalidate();
    return 0;
}

LRESULT COpenCVTestView::OnEraseBkgnd(
    UINT    /*uMsg*/,
    WPARAM  /*wParam*/,
    LPARAM  /*lParam*/,
    BOOL&   /*bHandled*/
) {
    // поскольку окно полностью перерисовано в обработчике OnPaint,
    // здесь можно не делать ничего
    return 0;
} 
