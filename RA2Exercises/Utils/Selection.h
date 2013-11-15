#ifndef SELECTION_H
#define SELECTION_H

// Event selection helper functions and cut values.
//
// Author: Matthias Schroeder
//         matthias.schroeder@AT@desy.de
//         November 2013
class Selection {
public:
  // Returns result of delta-phi selection
  static bool deltaPhi(double dPhi1, double dPhi2, double dPhi3) {
    return dPhi1 > 0.5 && dPhi2 > 0.5 && dPhi3 > 0.3;
  }

  // Returns result of HT baseline selection
  static bool ht(double ht) { return ht > 500.; }

  // Returns result of MHT baseline selection
  static bool mht(double mht) { return mht > 200.; }

  // Returns result of N(jets) baseline selection
  static bool nJets(unsigned int nJets) { return nJets >= 3; }

  // Returns result of search-bin selection (to be applied on top
  // of baseline selection)
  static unsigned int searchBin(double ht, double mht, unsigned int nJets);

  // Cut values for HT jets
  static float htJetPtMin() { return 50.; }
  static float htJetEtaMax() { return 2.5; }

  // Cut values for MHT jets
  static float mhtJetPtMin() { return 30.; }
  static float mhtJetEtaMax() { return 5.0; }

};


unsigned int Selection::searchBin(double ht, double mht, unsigned int nJets) {
  unsigned int bin = 0;

  if( nJets >= 3 && nJets <= 5 ) {
    
    if( ht > 500 && ht < 800 ) {

      if(      mht > 200 && mht < 300 ) bin = 1;
      else if( mht > 300 && mht < 450 ) bin = 2;
      else if( mht > 450 && mht < 600 ) bin = 3;
      else if( mht > 600              ) bin = 4;

    } else if( ht > 1000 && ht < 1250 ) {

      if(      mht > 200 && mht < 300 ) bin = 9;
      else if( mht > 300 && mht < 450 ) bin = 10;
      else if( mht > 450 && mht < 600 ) bin = 11;
      else if( mht > 600              ) bin = 12;

    }


  }

  return bin;
}
#endif

