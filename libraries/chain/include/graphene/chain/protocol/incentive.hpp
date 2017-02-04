/*
 * Copyright (c) 2015 Cryptonomex, Inc., and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once
#include <graphene/chain/protocol/base.hpp>

namespace graphene { namespace chain { 

  /**
    * @brief make an incentive.
    *
    * on every new block creation, there will be a incentive transaction which 
    * records how incentive coins goes
    */
   struct incentive_operation : public base_operation
   {
      struct fee_parameters_type
      {
         share_type fee = 1;
      };

      asset             fee;

      /// account who produced block get 3.14% share of incentive
      account_id_type   witness_account;
      uint64_t          total_coins;
      vector<account_id_type> accounts; 

      account_id_type fee_payer()const { return witness_account; }
      void            validate()const;
   };


} } // graphene::chain

FC_REFLECT( graphene::chain::incentive_operation::fee_parameters_type, (fee) )
FC_REFLECT( graphene::chain::incentive_operation, (fee)(witness_account)(total_coins)(accounts) )
