import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';

const Square = ({ onClick, value}) => {
  return (
    <button className="square" 
      onClick= {onClick}>
      { value }
    </button>
  )
}

export default Square;