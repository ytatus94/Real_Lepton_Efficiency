// Compare the error propagation formula
// between Sebastien and my equation.
//
void compare_error_propagation()
{
    // code to test uncertainty calculation
    // Data: Baseline in the tail = 1069 +- 32.6956(3.05852%)
    // Data: (Baseline - Signal) in the tail = 918 +- 30.2985(3.30049%)
    // Template baseline in the tail (fitting) = 134.49 +- 11.597(8.62292%)
    // MC: Signal in the tail = 99.4507 +- 9.9725(10.0276%)
    // MC: Baseline in the tail = 338.043 +- 18.386(5.43893%)
    // MC: Signal/Baseline ratio in the tail = 0.294195 +- 0.0247841
    // MC: (Baseline - Signal) in the tail = 238.593 +- 15.4464(6.47398%)

    TH1F *k1 = new TH1F("k1"," (A-B/C1)/D1",100,0,20);
    TH1F *k2 = new TH1F("k2"," (A-B/C)/D",100,0,20);

    Double_t mean_A = 1069.;
    Double_t sigma_A = 32.6956;

    Double_t mean_B = 99.4507;
    Double_t sigma_B = 9.9725;

    Double_t mean_C = 0.294195;
    Double_t sigma_C = 0.0247841;
    
    Double_t mean_D = 134.49;
    Double_t sigma_D = 11.597;

    Double_t mean_E = 918.;
    Double_t sigma_E = 30.2985;

    for (Int_t i = 0; i < 6000; i++) {
        Double_t A = gRandom->Gaus(mean_A, sigma_A);
        Double_t B = gRandom->Gaus(mean_B, sigma_B);
        Double_t C = gRandom->Gaus(mean_C, sigma_C);
        Double_t D = gRandom->Gaus(mean_D, sigma_D);
        Double_t C1 = mean_C; // const
        Double_t D1 = mean_D; // const
        Double_t result1 = (A - B/C1)/D1;
        Double_t result2 = (A - B/C)/D;
        k1->Fill(result1);
        k2->Fill(result2);
    }

    k1->SetStats(kFALSE);
    k1->Draw();
    k2->SetLineColor(2);
    k2->Draw("same");

    TLegend *leg = new TLegend(0.4, 0.6, 0.8, 0.8);
    leg->AddEntry(k1, "C1 & D1 are constants", "l");
    leg->AddEntry(k2, "C1 & D1 are distributions", "l");
    leg->SetBorderSize(0);
    leg->SetTextSize(0.04);
    leg->Draw("same");
    
    // fractional error^2=(Delta A/A)^+(Delta B/B)^2 + (Delta C/C)^2
    Float_t seb_error_calculation = sqrt((mean_B * pow((mean_C - 1) / mean_C, 2) + mean_E)) / mean_D;
    Float_t my_error_calculation_1 = sqrt(mean_B * (pow(mean_C, 2) + 1) / pow(mean_C, 2) + mean_E) / mean_D;
 
    Float_t hist_error1=k1->GetRMS();
    Float_t hist_mean1=k1->GetMean();

    cout << "hist_error1=" << hist_error1 << endl;
    cout << "Sebastien's results=" << seb_error_calculation << endl;
    cout << "My results1=" << my_error_calculation_1 << endl;

    Float_t my_error_calculation_2 = sqrt((pow(sigma_A, 2) + pow(mean_B/mean_C, 2)*(pow(sigma_B/mean_B, 2) + pow(sigma_C/mean_C, 2)))/pow(mean_A - mean_B/mean_C, 2) + pow(sigma_D/mean_D, 2));



    Float_t hist_error2=k2->GetRMS();
    Float_t hist_mean2=k2->GetMean();

    cout << "hist_error2=" << hist_error2 << endl;
    cout << "My results2=" << my_error_calculation_2 * hist_mean2 << endl;
}