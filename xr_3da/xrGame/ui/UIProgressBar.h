//////////////////////////////////////////////////////////////////////
// UIProgressBar.h: полоса процента выполнения
//////////////////////////////////////////////////////////////////////

#ifndef _UI_PROGRESSBAR_H_
#define _UI_PROGRESSBAR_H_

#pragma once

#include "uiwindow.h"
#include "uibutton.h"
#include "../script_export_space.h"


class CUIProgressBar : public CUIWindow
{
	friend class CUIXmlInit;
	typedef CUIWindow	inherited;
protected:
	//горизонтальный или вертикальный 
	bool			m_bIsHorizontal;

	//текущая позиция
	Fvector2		m_ProgressPos; // x - current, y - target
	//границы отображения
	float			m_iMinPos;
	float			m_iMaxPos;

	//текущий состояние полосы в пикселях
	float				m_iCurrentLength;

	///////////////////////////////////////	
	//Графический интрефейс для рисования
	///////////////////////////////////////
	//вывод при помощи тайлов, иначе вся текстура - показывает 100% прогресса
	float				m_iProgressLength;

	//items
	CUIStaticItem	m_UIProgressItem;
	CUIStaticItem	m_UIBackgroundItem;
	bool			m_bBackgroundPresent;
	Fvector2		m_BackgroundOffset;

	u32				m_last_render_frame;

	//обновить полосу
	void			UpdateProgressBar();

	DECLARE_SCRIPT_REGISTER_FUNCTION
public:
	bool			m_bUseColor;
	Fcolor			m_minColor;
	Fcolor			m_maxColor;

	float			m_inertion;

public:
					CUIProgressBar(void);
	virtual			~CUIProgressBar(void);


	virtual void	Init(float x, float y, float length, float broad, bool bIsHorizontal);

	void			SetProgressTexture(LPCSTR tex_name, float progress_length, 
						float x, float y, float width, float height, u32 color = 0xFFFFFFFF);
	void			SetBackgroundTexture(LPCSTR tex_name, float x, float y, float width, float height, float offs_x, float offs_y);

	void			SetRange(float iMin, float iMax)
	{
		m_iMinPos = iMin;
		m_iMaxPos = iMax;
		UpdateProgressBar();
	}

	void			GetRange(s16& iMin, s16& iMax) {iMin = m_iMinPos;  iMax = m_iMaxPos;}

	float			GetRange_min() { return m_iMinPos; }
	float			GetRange_max() { return m_iMaxPos; }

	void			SetProgressPos(float iPos);
	float			GetProgressPos() { return m_ProgressPos.y; }

	//базовые размеры для кнопок
	//enum {PROGRESSBAR_WIDTH = 32, PROGRESSBAR_HEIGHT = 32};


	//передвинуть каретку, если возможно
	bool			ProgressInc();
	bool			ProgressDec();

	virtual void	Draw();
	virtual void	Update();
};

add_to_type_list(CUIProgressBar)
#undef script_type_list
#define script_type_list save_type_list(CUIProgressBar)

#endif //_UI_PROGRESSBAR_H_