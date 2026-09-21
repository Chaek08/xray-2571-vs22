#pragma once

class CUIMotionIcon : public CUIStatic
{
	typedef CUIWindow inherited;
public:
	enum	EState		{
						stNormal,
						stCrouch,
						stCreep,
						stClimb,
						stRun,
						stSprint,
						stLast
					};
private:
							EState				m_curren_state;
							CUIStatic			m_states[stLast];
							CUIProgressBar		m_power_progress;
							CUIProgressBar		m_luminosity_progress;
							CUIProgressBar		m_noise_progress;
public:
	virtual					~CUIMotionIcon		();
							CUIMotionIcon		();
			void			Init				();
			void			ShowState			(EState state);
			void			SetPower			(float Pos);
			void			SetNoise			(float Pos);
			void			SetLuminosity		(float Pos);
};
