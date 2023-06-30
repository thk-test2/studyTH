import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';

class Game extends React.Component {
  render() {
    return <div>
      <App />
    </div>
  }
}

// ========================================

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<Game />);
