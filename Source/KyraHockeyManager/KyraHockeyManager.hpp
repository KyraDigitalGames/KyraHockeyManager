#ifndef KYRAHOCKEYMANAGER_KYRAHOCKEYMANAGER_HPP
#define KYRAHOCKEYMANAGER_KYRAHOCKEYMANAGER_HPP

#include <KyraGameEngine/Application.hpp>

namespace khm {

  class KyraHockeyManager : public kyra::Application {

  public:

    bool init();
    const kyra::WindowDescriptor getWindowDescriptor() const final;

  };

}

#endif