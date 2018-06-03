/*
 * Copyright (C) 2018 Sygram
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * File:   TrainerBPC.h
 * Author: Sygram
 *
 * Created on May 14, 2018, 7:16 PM
 */

#ifndef TRAINERBPC_H
#define TRAINERBPC_H

#include "Trainer.h"
#include "Estructura.h"
#include "NodeTraineeBPC.h"

namespace rdf {
  namespace bpc {

    class Trainer : public rdf::Trainer{
    public:
      Trainer();
      Trainer(const Trainer& orig);
      void Train(Node*, std::vector<Estructura::Node>&, rdf::NodeResult&); //TODO - Finish implementation
      virtual ~Trainer();
    private:

    };

  } /* bpc */
} /* rdf */

#endif /* TRAINERBPC_H */
