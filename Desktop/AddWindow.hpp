#pragma once

#include <wx/wx.h>
#include "lib/Item.hpp"
#include "dbHelper.hpp"

class AddWindow : public wxFrame {
	dbHelper* database = nullptr;
	wxTextCtrl* txtName = nullptr;
	wxButton* btnConfirm = nullptr;

public:
	AddWindow(wxSize parentSize, wxPoint parentPos);
	~AddWindow();
};