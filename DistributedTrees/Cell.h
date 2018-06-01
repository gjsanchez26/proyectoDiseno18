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
 * File:   Cell.h
 * Author: Sygram
 *
 * Created on May 5, 2018, 4:06 PM
 */

#ifndef CELL_H
#define CELL_H


namespace rdf {

  class Cell {
  public:
    Cell();
    Cell(const Cell& orig);
    // virtual void Reduce(const Cell& other) = 0; //FIXME
    virtual ~Cell();
  private:

  };

} /* rdf */

#endif /* CELL_H */
