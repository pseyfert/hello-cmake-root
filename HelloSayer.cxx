#include "TH1F.h"
#include "TCanvas.h"

int main() {
  TH1F* h = new TH1F("h","h",200,-5,5);
  for (int i = 0 ; i < 30 ; ++i) h->FillRandom("gaus");
  TCanvas c;
  h->Draw();
  c.Print("foobar.png");
  return 0;
}
