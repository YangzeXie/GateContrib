/*----------------------
   GATE version name: gate_v6

   Copyright (C): OpenGATE Collaboration

This software is distributed under the terms
of the GNU Lesser General  Public Licence (LGPL)
See GATE/LICENSE.txt for further details
----------------------*/

#include "GateConfiguration.h"

#include "GateElectronIonisationPenelopePB.hh"

#include "GateEMStandardProcessMessenger.hh"


//-----------------------------------------------------------------------------
GateElectronIonisationPenelopePB::GateElectronIonisationPenelopePB():GateVProcess("PenelopeElectronIonisation")
{  
  SetDefaultParticle("e+");
  SetDefaultParticle("e-");
  SetProcessInfo("Ionization and energy loss by electrons and positrons (Penelope)");

  pMessenger = new GateEMStandardProcessMessenger(this);  
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
G4VProcess* GateElectronIonisationPenelopePB::CreateProcess(G4ParticleDefinition * par)
{
  return dynamic_cast<G4VProcess*>( new G4PenelopeIonisationModel(par, GetG4ProcessName()) );
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
void GateElectronIonisationPenelopePB::ConstructProcess(G4ProcessManager * manager)
{
  manager->AddProcess(GetProcess(),-1, 2, 2);           
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
bool GateElectronIonisationPenelopePB::IsApplicable(G4ParticleDefinition * par)
{
  if(par == G4Electron::Electron() || par == G4Positron::Positron()) return true;
  return false;
}
//-----------------------------------------------------------------------------

MAKE_PROCESS_AUTO_CREATOR_CC(GateElectronIonisationPenelopePB)

