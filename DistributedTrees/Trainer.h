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
 * File:   Trainer.h
 * Author: Sygram
 *
 * Created on May 14, 2018, 7:16 PM
 */

#ifndef TRAINER_H
#define TRAINER_H

#include "Node.h"
#include <vector>
#include "Estructura.h"
#include "NodeResult.h"


namespace rdf {

  class Trainer {
  public:
    Trainer();
    Trainer(const Trainer& orig);
    virtual void Train(Node*, std::vector<Estructura::Node>&, NodeResult&) = 0;
    virtual ~Trainer();
  private:

  };

} /* rdf */


#endif /* TRAINER_H */
