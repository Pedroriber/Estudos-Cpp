//#include <stdlib.h>
//#include <iup.h>

//int main(int argc, char** argv)
//{
//	IupOpen(&argc, &argv);
//
//	IupMessage("Hello World 1", "Hello world from IUP.");
//
//	IupClose();
//	return EXIT_SUCCESS;
//}

//#include <stdlib.h>
//#include <iup.h>
//
//int main(int argc, char** argv)
//{
//	Ihandle* dlg, * label;
//
//	IupOpen(&argc, &argv);
//
//	label = IupLabel("      Hello world from IUP.          ");
//	dlg = IupDialog(IupVbox(label, NULL));
//	IupSetAttribute(dlg, "TITLE", "           Hello World 2");
//
//	IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
//
//	IupMainLoop();
//
//	IupClose();
//	return EXIT_SUCCESS;
// }

#include<stdlib.h>
#include<iup.h>

int btn_sair(Ihandle* self) {
	IupMessage("voce saiu", "EXIT");
	return IUP_CLOSE;
}

int main(int argc, char** argv) {
	Ihandle* dlg, * button, * vbox, * label;
	IupOpen(&argc, &argv);
	button = IupButton("sair", NULL);
	label = IupLabel("Você quer sair?");
	vbox = IupVbox(label,  button, NULL);
	dlg = IupDialog(vbox);
	IupSetAttribute(dlg, "TITLE", "Helllo World");
	IupSetAttribute(vbox, "ALIGNMENT", "RIGHT");
	IupSetAttribute(vbox, "GAP", "10");
	IupSetAttribute(vbox, "MARGIN", "100x100");
	IupSetCallback(button, "ACTION", (Icallback)btn_sair);
	IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
	IupMainLoop();

	IupClose();
	return EXIT_SUCCESS;
}