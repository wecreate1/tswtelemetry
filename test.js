// (async ()=> {
const socket = new WebSocket('ws://localhost:6865/app');
socket.addEventListener('message', event => {
    try {
        const receivedData = JSON.parse(event.data);
        console.log(new Date(), 'Received JSON:', receivedData);
    } catch (error) {
        console.error('Error parsing JSON:', error);
        console.log('Received data was:', event.data);
    }
});

// await new Promise(()=>{});
// })();