#include "WxMoviePlayer.hpp"
BEGIN_EVENT_TABLE( WxMoviePlayer, wxWindow )
  EVT_PAINT( WxMoviePlayer::OnPaint )
  EVT_TIMER( TIMER_ID, WxMoviePlayer::OnTimer )
  EVT_CHAR( WxMoviePlayer::OnKey )
END_EVENT_TABLE()

WxMoviePlayer::WxMoviePlayer( wxWindow* parent, const wxPoint& pos, const wxSize&  size) : wxWindow( parent, -1, pos, size, wxSIMPLE_BORDER ) 
{
    m_timer = NULL;
    m_parentb = parent;
}

void WxMoviePlayer::OnPaint(wxPaintEvent& event) 
{
	wxPaintDC dc(this);
	if(!dc.Ok()) 
        return;
	int x, y, w, h;
	dc.BeginDrawing();
	dc.GetClippingBox(&x, &y, &w, &h);
	dc.DrawBitmap(m_wx_bmp, x, y);
	dc.EndDrawing();
	return;
}

void WxMoviePlayer::_copyImage(void) 
{
	m_wx_bmp = wxBitmap(m_wx_img);
	Refresh(FALSE);
    Update();
}

bool WxMoviePlayer::open(wxString file) 
{
	if(!m_cap.open(std::string(file.mb_str())))
	    return false;
	
	m_cap.read(m_cv_img);
	m_wx_img = wxImage(m_cv_img.cols, m_cv_img.rows, m_cv_img.data, TRUE);
	_copyImage();
	m_timer = new wxTimer(this, TIMER_ID);
	m_timer->Start(1000. / m_cap.get(cv::CAP_PROP_FPS));
	return true;
}

void WxMoviePlayer::OnTimer(wxTimerEvent& event) 
{
	if(!m_cap.isOpened()) 
        return;
	m_cap.read(m_cv_img);
	cv::cvtColor(m_cv_img, m_cv_img, cv::BGR2RGB);
	_copyImage();
}

void WxMoviePlayer::OnKey(wxKeyEvent& e) 
{
	if(e.GetKeyCode() == WXK_ESCAPE) 
        m_parent->Close();
}
