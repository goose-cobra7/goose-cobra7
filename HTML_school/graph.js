document.addEventListener('DOMContentLoaded', function() {
  const width = window.innerWidth;
  const height = window.innerHeight;

  const svg = d3.select('svg')
    .attr('width', width)
    .attr('height', height);

  const notes = [
    { id: 'note1', label: 'Note 1' },
    { id: 'note2', label: 'Note 2' },
    { id: 'note3', label: 'Note 3' },
    { id: 'note4', label: 'Note 4' }
  ];

  const links = [
    { source: 'note1', target: 'note2' },
    { source: 'note2', target: 'note3' },
    { source: 'note3', target: 'note4' },
    { source: 'note1', target: 'note4' }
  ];

  const simulation = d3.forceSimulation(notes)
    .force('link', d3.forceLink(links).id(d => d.id))
    .force('charge', d3.forceManyBody().strength(-200))
    .force('center', d3.forceCenter(width / 2, height / 2));

  const link = svg.append('g')
    .attr('class', 'links')
    .selectAll('line')
    .data(links)
    .enter().append('line')
    .attr('stroke', '#abb2bf')
    .attr('stroke-width', 2);

  const node = svg.append('g')
    .attr('class', 'nodes')
    .selectAll('circle')
    .data(notes)
    .enter().append('circle')
    .attr('r', 20)
    .attr('fill', '#32343f')
    .attr('stroke', '#444')
    .attr('stroke-width', 2)
    .call(d3.drag()
      .on('start', dragstarted)
      .on('drag', dragged)
      .on('end', dragended));

  const label = svg.append('g')
    .attr('class', 'labels')
    .selectAll('text')
    .data(notes)
    .enter().append('text')
    .attr('dy', '.35em')
    .attr('text-anchor', 'middle')
    .attr('fill', '#abb2bf')
    .text(d => d.label);

  simulation
    .on('tick', () => {
      link
        .attr('x1', d => d.source.x)
        .attr('y1', d => d.source.y)
        .attr('x2', d => d.target.x)
        .attr('y2', d => d.target.y);

      node
        .attr('cx', d => d.x)
        .attr('cy', d => d.y);

      label
        .attr('x', d => d.x)
        .attr('y', d => d.y);
    });

  function dragstarted(event, d) {
    if (!event.active) simulation.alphaTarget(0.3).restart();
    d.fx = d.x;
    d.fy = d.y;
  }

  function dragged(event, d) {
    d.fx = event.x;
    d.fy = event.y;
  }

  function dragended(event, d) {
    if (!event.active) simulation.alphaTarget(0);
    d.fx = null;
    d.fy = null;
  }
});
